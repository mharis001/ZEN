#include "script_component.hpp"
/*
 * Author: mharis001
 * Opens a dialog for entering the category and name of a composition.
 *
 * Arguments:
 * 0: Mode <STRING>
 * 1: Composition <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["create", ["", "", []]] call zen_compositions_fnc_openDisplay
 *
 * Public: No
 */

params ["_mode", "_composition"];

createDialog QGVAR(display);
private _display = uiNamespace getVariable QGVAR(display);

// Add previously entered category names to list for QOL
private _ctrlList = _display displayCtrl IDC_DISPLAY_LIST;
_ctrlList ctrlAddEventHandler ["LBSelChanged", {
    params ["_ctrlList", "_index"];

    private _display = ctrlParent _ctrlList;
    private _ctrlCategory = _display displayCtrl IDC_DISPLAY_CATEGORY;
    _ctrlCategory ctrlSetText (_ctrlList lbText _index);

    _display call (_display getVariable QFUNC(verify));
}];

private _categories = [];

{
    _x params ["_category"];

    if (_categories pushBackUnique _category != -1) then {
        _ctrlList lbAdd _category;
    };
} forEach GET_COMPOSITIONS;

// Verify entered values (not empty, unique category and name combination)
_display setVariable [QFUNC(verify), {
    params ["_display"];

    private _ctrlCategory = _display displayCtrl IDC_DISPLAY_CATEGORY;
    private _ctrlName     = _display displayCtrl IDC_DISPLAY_NAME;
    private _ctrlButtonOK = _display displayCtrl IDC_OK;

    private _category = ctrlText _ctrlCategory;
    private _name = ctrlText _ctrlName;

    if (_category == "") exitWith {
        _ctrlButtonOK ctrlEnable false;
        _ctrlButtonOK ctrlSetTooltip localize LSTRING(CategoryCannotBeEmpty);
    };

    if (_name == "") exitWith {
        _ctrlButtonOK ctrlEnable false;
        _ctrlButtonOK ctrlSetTooltip localize LSTRING(NameCannotBeEmpty);
    };

    private _enable = FIND_COMPOSITION(_category,_name) == -1;
    private _tooltip = if (_enable) then {""} else {localize LSTRING(CompositionAlreadyExists)};

    _ctrlButtonOK ctrlEnable _enable;
    _ctrlButtonOK ctrlSetTooltip _tooltip;
}];

// Verify every time inputs are changed
private _fnc_update = {
    params ["_ctrl"];

    private _display = ctrlParent _ctrl;
    _display call (_display getVariable QFUNC(verify));
};

private _ctrlCategory = _display displayCtrl IDC_DISPLAY_CATEGORY;
_ctrlCategory ctrlAddEventHandler ["KeyDown", _fnc_update];
_ctrlCategory ctrlAddEventHandler ["KeyUp", _fnc_update];

private _ctrlName = _display displayCtrl IDC_DISPLAY_NAME;
_ctrlName ctrlAddEventHandler ["KeyDown", _fnc_update];
_ctrlName ctrlAddEventHandler ["KeyUp", _fnc_update];

// Set the title based on the mode
private _ctrlTitle = _display displayCtrl IDC_DISPLAY_TITLE;
private _title = [LSTRING(EditCustomComposition), LSTRING(CreateCustomComposition)] select (_mode == "create");
_ctrlTitle ctrlSetText localize _title;

// Set the current composition category and name
_composition params ["_category", "_name"];
_ctrlCategory ctrlSetText _category;
_ctrlName ctrlSetText _name;

// Run initial verification of values
_display call (_display getVariable QFUNC(verify));

private _ctrlButtonOK = _display displayCtrl IDC_OK;

[_ctrlButtonOK, "ButtonClick", {
    params ["_ctrlButtonOK"];
    _thisArgs params ["_mode", "_composition"];

    private _display = ctrlParent _ctrlButtonOK;
    private _ctrlCategory = _display displayCtrl IDC_DISPLAY_CATEGORY;
    private _ctrlName     = _display displayCtrl IDC_DISPLAY_NAME;

    // Set the new composition category and name
    _composition set [0, ctrlText _ctrlCategory];
    _composition set [1, ctrlText _ctrlName];

    if (_mode == "create") then {
        // In create mode, add the composition to saved data
        private _compositions = GET_COMPOSITIONS;
        _compositions pushBack _composition;
        SET_COMPOSITIONS(_compositions);
    } else {
        // In edit mode, remove the old composition from the tree
        [false] call FUNC(removeFromTree);
    };

    GVAR(treeAdditions) pushBack _composition;
    [findDisplay IDD_RSCDISPLAYCURATOR] call FUNC(processTreeAdditions);
}, _this] call CBA_fnc_addBISEventHandler;