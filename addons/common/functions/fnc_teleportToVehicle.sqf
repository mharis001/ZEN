/*
 * Author: 3Mydlo3
 * Teleports units to the given vehicle.
 *
 * Arguments:
 * 0: Units <ARRAY>
 * 1: Vehicle <OBJECT>
 *
 * Return Value:
 * Success <BOOL>
 *
 * Example:
 * [[player1, player2, player3], vehicle player] call zen_common_fnc_teleportToVehicle
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_units", "_vehicle"];

private _success = false;

if (_vehicle isKindOf "AllVehicles" && {!(_vehicle isKindOf "CAManBase")}) then {
    private _freeCargoSpace = {_x#0 isEqualTo objNull} count fullCrew [_vehicle, "", true];
    private _unitsNotInTargetVehicle = _units select {!(_x in _vehicle)};

    if ((count _unitsNotInTargetVehicle) <= _freeCargoSpace) then {
        {
            _x moveInAny _vehicle;
        } forEach _unitsNotInTargetVehicle;
        _success = true;
    };
};

_success
