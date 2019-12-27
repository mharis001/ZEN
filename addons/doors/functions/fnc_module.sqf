#include "script_component.hpp"
/*
 * Author: mharis001
 * Zeus module function to configure the doors of a building.
 *
 * Arguments:
 * 0: Logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [LOGIC] call zen_doors_fnc_module
 *
 * Public: No
 */

params ["_logic"];

// Use attached building first then search nearby
private _building = attachedTo _logic;

if (isNull _building || {!(_building isKindOf "Building")}) then {
    _building = nearestObject [_logic, "Building"];
};

deleteVehicle _logic;

// Exit if no building attached or nearby
if (isNull _building) exitWith {
    [LSTRING(NoBuilding)] call EFUNC(common,showMessage);
};

[_building] call FUNC(configure);
