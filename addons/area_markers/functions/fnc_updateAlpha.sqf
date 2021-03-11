#include "script_component.hpp"
/*
 * Author: Fusselwurm
 * Set the alpha of a marker depending on the player's side.
 *
 * Arguments:
 * 0: Marker <STRING>
 * 1: Sides that may see the marker <ARRAY>
 * 2: Alpha value to use for players of passed `sides` <SCALAR>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["marker_0", [west, civilian], 0.7] call zen_area_markers_fnc_updateAlpha
 *
 * Public: No
 */

params ["_marker", "_sides", "_alpha"];

if (isServer) then {
    [GVAR(markerVisibilities), _marker, _sides] call CBA_fnc_hashSet;
    publicVariable QGVAR(markerVisibilities);
    [GVAR(markerAlphas), _marker, _alpha] call CBA_fnc_hashSet;
    publicVariable QGVAR(markerAlphas);
};

if (hasInterface) then {
    private _isVisibleSide = (side player) in _sides;
    private _isZeus = !isNull curatorCamera;

    if (_isVisibleSide || _isZeus) then {
        _marker setMarkerAlphaLocal _alpha;
    } else {
        _marker setMarkerAlphaLocal 0;
    };
};
