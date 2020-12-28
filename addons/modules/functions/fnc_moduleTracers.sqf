#include "script_component.hpp"
/*
 * Author: Ampersand
 * Zeus module function to shoot tracers.
 *
 * Arguments:
 * 0: Display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [DISPLAY] call zen_modules_fnc_moduleTracers
 *
 * Public: No
 */

 params ["_display"];

 private _logic = GETMVAR(BIS_fnc_initCuratorAttributes_target,objNull);
 _display closeDisplay IDC_CANCEL; // Close helper display

 // Need to delay dialog creation by one frame to avoid weird input blocking bug
 [{
    params ["_logic"];

    // Default values: green tracers, 10-20s between bursts
    private _tracersParams = _logic getVariable [QGVAR(tracersParams), [east, 10, 20, 0.05, "", "", 0, ""]];
    _tracersParams params ["_side", "_min", "_max", "_dispersion", "_weapon", "_magazine", "_targetType", "_target"];

    ["str_a3_cfgvehicles_moduletracers_f_0", [
        [
            "SIDES",
            ELSTRING(attributes,ChangeSide),
            _side,
            true
        ],
        [
            "SLIDER",
            ["str_a3_cfgvehicles_moduletracers_f_arguments_min_0", LSTRING(Tracers_MinDelay_Tooltip)],
             [0, 120, _min, 0],
             true
         ],
        [
            "SLIDER",
            ["str_a3_cfgvehicles_moduletracers_f_arguments_max_0", LSTRING(Tracers_MaxDelay_Tooltip)],
            [0, 120, _max, 0],
            true
        ],
        [
            "TOOLBOX",
            ELSTRING(attributes,Dispersion),
            [2, 1, 5, [
                ELSTRING(common,VeryLow),
                ELSTRING(common,Low),
                ELSTRING(common,Medium),
                ELSTRING(common,High),
                ELSTRING(common,VeryHigh)
            ]]
        ],
        [
            "EDIT",
            "str_a3_itemtype_category_weapon",
            _weapon,
            true
        ],
        [
            "EDIT",
            "str_a3_itemtype_category_magazine",
            _magazine,
            true
        ],
        [
            "TOOLBOX",
            ["str_a3_cfgvehicles_modulelivefeedsettarget_f_arguments_targettype_0", LSTRING(Tracers_TargetType_Tooltip)],
            [0, 1, 3, ["str_a3_no_target", ELSTRING(camera,DisplayName), ELSTRING(common,Cursor)]]
        ]
    ], {
        params ["_values", "_logic"];
        _values params ["_side", "_min", "_max", "_dispersion", "_weapon", "_magazine", "_targetType"];

        _dispersion = switch (_dispersion) do {
            case (0): {0.001};
            case (1): {0.01};
            case (2): {0.05};
            case (3): {0.15};
            case (4): {0.3};
        };

        private _target = objNull;
        // select tracer target using cursor
        if (_targetType == 2) exitWith {
            [_logic, {
                params ["_successful", "_logic", "_position", "_args"];
                _args params ["_side", "_min", "_max", "_dispersion", "_weapon", "_magazine", "_targetType"];

                if (_successful) then {
                    curatorMouseOver params ["_type", "_entity"];

                    private _target = [_position, _entity] select (_type == "OBJECT");

                    _logic setVariable [QGVAR(tracersParams), [_side, _min, _max, _dispersion, _weapon, _magazine, _targetType, _target], true];
                    [QGVAR(moduleTracers), [_logic]] call CBA_fnc_serverEvent;
                };
            }, _values, ELSTRING(common,SelectPosition)] call EFUNC(common,selectPosition);
        };

        if (_targetType == 1) then {_target = AGLToASL positionCameraToWorld [0,0,0]};

        _logic setVariable [QGVAR(tracersParams), [_side, _min, _max, _dispersion, _weapon, _magazine, _targetType, _target], true];
        [QGVAR(moduleTracers), [_logic]] call CBA_fnc_serverEvent;

    }, {}, _logic] call EFUNC(dialog,create);
}, _logic] call CBA_fnc_execNextFrame;
