#include "script_component.hpp"
/*
 * Author: Jonpas
 * Finds the localized string of the given hitpoint name or uses the hitpoint name if none found.
 *
 * Arguments:
 * Hitpoint <STRING>
 *
 * Return Value:
 * Localized Hit Point Name <STRING>
 *
 * Example:
 * ["HitFuel"] call zen_common_fnc_getHitPointString
 *
 * Public: No
 */

params ["_hitPoint"];

// Prepare first part of the string from stringtable
private _text = LSTRING(Hit);

// Remove "Hit" from hitpoint name if one exists
private _toFind = if ((toLower _hitPoint) find "hit" == 0) then {
    [_hitPoint, 3] call CBA_fnc_substr
} else {
    _hitPoint
};

// Loop through always shorter part of the hitpoint name to find the string from stringtable
for "_i" from 0 to (count _hitPoint) do {
    // Localize if localization found
    private _combinedString = _text + _toFind;
    if (isLocalized _combinedString) exitWith {
        _text = localize _combinedString;
    };

    // Cut off one character
    _toFind = [_toFind, 0, count _toFind - 1] call CBA_fnc_substr;
};

// Don't display part name if no string is found in stringtable
if (_text == LSTRING(Hit)) then { _text = _hitPoint };

_text
