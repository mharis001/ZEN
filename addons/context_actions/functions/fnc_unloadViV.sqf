#include "script_component.hpp"
/*
 * Author: Ampersand
 * Unloads Vehicle-in-Vehicle cargo and carriers from the objects list.
 *
 * Arguments:
 * N: Objects <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_object] call zen_context_actions_fnc_unloadViV
 *
 * Public: No
 */

 {
     if (isNull isVehicleCargo _x) then {_x setVehicleCargo objNull} else {objNull setVehicleCargo _x};
 } forEach _this;
