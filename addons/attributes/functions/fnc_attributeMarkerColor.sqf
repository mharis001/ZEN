#include "script_component.hpp"
/*
 * Author: mharis001
 * Initializes the "Marker Color" Zeus attribute.
 *
 * Arguments:
 * 0: Display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [DISPLAY] call zen_attributes_fnc_attributeMarkerColor
 *
 * Public: No
 */

params ["_display"];

private _entity = GETMVAR(BIS_fnc_initCuratorAttributes_target,objNull);
private _ctrlButtonOK = _display displayCtrl IDC_OK;

private _ctrlCombo = _display displayCtrl IDC_MARKERCOLOR_COMBO;
private _markerColor = markerColor _entity;

{
    if (getNumber (_x >> "scope") > 0) then {
        private _name = getText (_x >> "name");
        private _class = configName _x;
        private _color = (_x >> "color") call BIS_fnc_colorConfigToRGBA;
        private _index = _ctrlCombo lbAdd _name;
        _ctrlCombo lbSetData [_index, _class];
        _ctrlCombo lbSetPicture [_index, "#(argb,8,8,3)color(1,1,1,1)"];
        _ctrlCombo lbSetPictureColor [_index, _color];
        _ctrlCombo lbSetPictureColorSelected [_index, _color];

        if (_class == _markerColor) then {
            _ctrlCombo lbSetCurSel _index;
        };
    };
} forEach ("true" configClasses (configFile >> "CfgMarkerColors"));

private _fnc_onConfirm = {
    params ["_ctrlButtonOK"];

    private _display = ctrlParent _ctrlButtonOK;
    private _entity = GETMVAR(BIS_fnc_initCuratorAttributes_target,objNull);

    private _ctrlCombo = _display displayCtrl IDC_MARKERCOLOR_COMBO;
    private _color = _ctrlCombo lbData lbCurSel _ctrlCombo;
    _entity setMarkerColor _color;

    // Set new markers of this type to have this color
    GVAR(markerColors) setVariable [markerType _entity, _color];
};

_ctrlButtonOK ctrlAddEventHandler ["ButtonClick", _fnc_onConfirm];
