#include "script_component.hpp"
/*
 * Author: NeilZar
 * Handles keyboard input for the loadout display.
 *
 * Arguments:
 * 0: Display <DISPLAY>
 * 1: Key Code <NUMBER>
 *
 * Return Value:
 * Handled <BOOL>
 *
 * Example:
 * [DISPLAY, 0] call zen_loadout_fnc_keyDown
 *
 * Public: No
 */

params ["_display", "_keyCode"];

// Exit if list is not in focus
if !(_display getVariable [QGVAR(listFocus), false]) exitWith {false};

switch (_keyCode) do {
    case DIK_LEFT;
    case DIK_NUMPADMINUS: {
        [_display, false] call FUNC(modify);
        true
    };
    case DIK_RIGHT;
    case DIK_NUMPADPLUS: {
        [_display, true] call FUNC(modify);
        true
    };
    default {false};
};
