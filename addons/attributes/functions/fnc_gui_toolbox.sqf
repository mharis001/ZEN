#include "script_component.hpp"
/*
 * Author: mharis001
 * Initializes the `toolbox` attribute control type.
 *
 * Arguments:
 * 0: Controls Group <CONTROL>
 * 1: Entity <OBJECT|GROUP|ARRAY|STRING>
 * 2: Default Value <BOOL|NUMBER>
 * 3: Value Info <ARRAY>
 *   0: Rows <NUMBER>
 *   1: Columns <NUMBER>
 *   2: Strings <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_controlsGroup, _entity, true, [1, 2, ["No", "Yes"]]] call zen_attributes_fnc_gui_toolbox
 *
 * Public: No
 */

params ["_controlsGroup", "_entity", "_defaultValue", "_valueInfo"];
_valueInfo params [["_rows", 1, [0]], ["_columns", 2, [0]], ["_strings", [], [[]]]];

private _returnBool = _defaultValue isEqualType false;

if (_returnBool) then {
    _defaultValue = parseNumber _defaultValue;
};

parsingNamespace setVariable [QGVAR(rows), _rows max 1];
parsingNamespace setVariable [QGVAR(columns), _columns max 2];

private _display = ctrlParent _controlsGroup;
private _ctrlToolbox = _display ctrlCreate [QGVAR(RscToolbox), IDC_ATTRIBUTE_TOOLBOX, _controlsGroup];
_ctrlToolbox setVariable [QGVAR(params), [_controlsGroup, _returnBool]];

// Currently the only way to add options to toolbox controls through script
{
    if (isLocalized _x) then {
        _x = localize _x;
    };

    _ctrlToolbox lbAdd _x;
} forEach _strings;

_ctrlToolbox lbSetCurSel _defaultValue;

_ctrlToolbox ctrlAddEventHandler ["ToolBoxSelChanged", {
    params ["_ctrlToolbox", "_value"];
    (_ctrlToolbox getVariable QGVAR(params)) params ["_controlsGroup", "_returnBool"];

    if (_returnBool) then {
        _value = _value > 0;
    };

    _controlsGroup setVariable [QGVAR(value), _value];
}];

if (_rows > 1) then {
    private _height = _rows * (ctrlPosition _controlsGroup select 3);
    _controlsGroup ctrlSetPositionH _height;
    _controlsGroup ctrlCommit 0;

    private _ctrlLabel = _controlsGroup controlsGroupCtrl IDC_ATTRIBUTE_LABEL;
    _ctrlLabel ctrlSetPositionH _height;
    _ctrlLabel ctrlCommit 0;

    _ctrlToolbox ctrlSetPositionH _height;
    _ctrlToolbox ctrlCommit 0;
};