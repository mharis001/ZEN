#include "script_component.hpp"
/*
 * Author: mharis001
 * Initializes the SLIDER content control.
 *
 * Arguments:
 * 0: Controls Group <CONTROL>
 * 1: Default Value <NUMBER>
 * 2: Settings <ARRAY>
 *   0: Minimum Value <NUMBER>
 *   1: Maximum Value <NUMBER>
 *   2: Formatting <NUMBER|CODE>
 *   3: Is Percentage <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [CONTROL, 5, [0, 10, 1, false]] call zen_dialog_fnc_gui_slider
 *
 * Public: No
 */

params ["_controlsGroup", "_defaultValue", "_settings"];
_settings params ["_min", "_max", "_formatting", "_isPercentage", "_drawRadius"];

private _ctrlSlider = _controlsGroup controlsGroupCtrl IDC_ROW_SLIDER;
private _ctrlEdit = _controlsGroup controlsGroupCtrl IDC_ROW_EDIT;
private _fnc_valueChanged = {};

if (_drawRadius && isNil QGVAR(drawRadiusEH)) then {
    // Get the attributes target or a selected object if not a module.
    if (isNil _logic) then { _logic = GETMVAR(BIS_fnc_initCuratorAttributes_target,objNull) };
    if (isNull _logic || {!(_logic isEqualType objNull)}) then { _logic = SELECTED_OBJECTS select 0 };

    // Don't draw the circle if nothing is selected or no module is placed.
    if !(isNil _logic || isNull _logic) then {
        GVAR(radiusOrigin) = ASLToAGL getPosASL _logic;
        GVAR(radius) = _defaultValue;

        GVAR(drawRadiusEH) = addMissionEventHandler ["Draw3D", {
            private _center = GVAR(radiusOrigin);
            private _radius = GVAR(radius);

            private _count = CIRCLE_DOTS_MIN max floor (2 * pi * _radius / CIRCLE_DOTS_SPACING);
            private _factor = 360 / _count;

            for "_i" from 0 to (_count - 1) do {
                private _phi = (_i * _factor);
                private _posVector = [_radius * cos(_phi), _radius * sin(_phi), 0];

                drawIcon3d ["\A3\ui_f\data\map\markers\military\dot_CA.paa", [1, 1, 1, 0.7], _center vectorAdd _posVector, CIRCLE_DOTS_SCALE, CIRCLE_DOTS_SCALE, 0];
            };
        }];

        _fnc_valueChanged = {
            params ["", "", "_value"];

            GVAR(radius) = _value;
        };
    };
};

[_ctrlSlider, _ctrlEdit, _min, _max, _defaultValue, -1, _formatting, _isPercentage, _fnc_valueChanged] call EFUNC(common,initSliderEdit);

_controlsGroup setVariable [QFUNC(value), {
    params ["_controlsGroup"];

    sliderPosition (_controlsGroup controlsGroupCtrl IDC_ROW_SLIDER)
}];
