#include "script_component.hpp"
/*
 * Author: mharis001
 * Returns deep copy data for the given objects.
 *
 * Arguments:
 * 0: Objects <ARRAY>
 *
 * Return Value:
 * Object Data <ARRAY>
 *
 * Example:
 * [_objects] call zen_editor_fnc_deepCopy
 *
 * Public: No
 */

params ["_objects"];

// Filter destroyed objects and get the vehicle for mounted infantry
_objects = _objects select {alive _x && {isNull isVehicleCargo _x}} apply {vehicle _x};
_objects = _objects arrayIntersect _objects;

// Get the world position where the cursor is pointing
// Object positions are copied relative to the cursor
private _centerPos = ASLtoAGL ([nil, false] call EFUNC(common,getPosFromScreen));

private _units = [];
private _vehicles = [];
private _statics = [];

private _groups = [];
private _indexedGroups = [];

private _fnc_serializeGroup = {
    params ["_unit"];

    private _group = group _unit;
    private _index = _indexedGroups find _group;

    if (_index == -1) then {
        _index = _indexedGroups pushBack _group;

        private _waypoints = waypoints _group apply {
            _x call _fnc_serializeWaypoint
        };

        _groups pushBack [side _group, formation _group, behaviour leader _group, combatMode _group, speedMode _group, currentWaypoint _group, _waypoints];
    };

    _index
};

private _fnc_serializeWaypoint = {
    [_this] params ["_waypoint"];

    [
        waypointType _waypoint,
        waypointName _waypoint,
        waypointDescription _waypoint,
        waypointPosition _waypoint vectorDiff _centerPos,
        waypointFormation _waypoint,
        waypointBehaviour _waypoint,
        waypointCombatMode _waypoint,
        waypointSpeed _waypoint,
        waypointTimeout _waypoint,
        waypointCompletionRadius _waypoint,
        waypointStatements _waypoint,
        waypointScript _waypoint
    ]
};

private _fnc_serializeUnit = {
    params ["_unit"];

    private _type = typeOf _unit;
    private _position = getPosATL _unit vectorDiff _centerPos;
    private _direction = getDir _unit;

    private _name = name _unit;
    private _face = face _unit;
    private _speaker = speaker _unit;
    private _pitch = pitch _unit;
    private _nameSound = nameSound _unit;

    private _rank = rank _unit;
    private _skill = skill _unit;
    private _stance = unitPos _unit;
    private _loadout = getUnitLoadout _unit;

    private _group = _unit call _fnc_serializeGroup;
    private _isLeader = leader _unit == _unit;

    [_type, _position, _direction, [_name, _face, _speaker, _pitch, _nameSound], _rank, _skill, _stance, _loadout, _group, _isLeader]
};

private _fnc_serializeVehicle = {
    params ["_vehicle"];

    private _type = typeOf _vehicle;
    private _dirAndUp = [vectorDir _vehicle, vectorUp _vehicle];
    private _simulation = getText (configFile >> "CfgVehicles" >> _type >> "simulation");

    // Use position AGL if vehicle is boat or amphibious
    private _position = if (_simulation == "ship" || {_simulation == "shipx"}) then {
        ASLtoAGL getPosASL _vehicle
    } else {
        getPosATL _vehicle
    };

    _position = _position vectorDiff _centerPos;

    private _fuel = fuel _vehicle;
    private _damage = damage _vehicle;
    private _hitPointsDamage = getAllHitPointsDamage _vehicle select 2;

    private _inventory = _vehicle call EFUNC(common,serializeInventory);
    private _customization = _vehicle call BIS_fnc_getVehicleCustomization;

    private _allPylonMagazines = getPylonMagazines _vehicle;

    private _turretMagazines = magazinesAllTurrets _vehicle select {
        !(_x select 0 in _allPylonMagazines)
    } apply {
        _x select [0, 3] // Discard ID and creator
    };

    private _pylonMagazines = [];

    {
        private _turretPath = [_vehicle, _forEachIndex] call EFUNC(common,getPylonTurret);
        private _ammoCount = _vehicle ammoOnPylon (_forEachIndex + 1);

        _pylonMagazines pushBack [_x, _turretPath, _ammoCount];
    } forEach _allPylonMagazines;

    private _vehicleCargo = getVehicleCargo _vehicle apply {
        _x call _fnc_serializeVehicle
    };

    private _crew = fullCrew _vehicle apply {
        _x params ["_unit", "_role", "_cargoIndex", "_turretPath"];

        [_unit call _fnc_serializeUnit, toLower _role, _cargoIndex, _turretPath]
    };

    [_type, _position, _dirAndUp, _fuel, _damage, _hitPointsDamage, _inventory, _customization, _turretMagazines, _pylonMagazines, _vehicleCargo, _crew]
};

private _fnc_serializeStatic = {
    params ["_object"];

    private _type = typeOf _x;
    private _position = getPosATL _object vectorDiff _centerPos;
    private _dirAndUp = [vectorDir _object, vectorUp _object];

    private _damage = damage _object;
    private _inventory = _object call EFUNC(common,serializeInventory);

    [_type, _position, _dirAndUp, _damage, _inventory]
};

{
    switch (true) do {
        case (_x isKindOf "CAManBase"): {
            _units pushBack (_x call _fnc_serializeUnit);
        };
        case (_x isKindOf "AllVehicles"): {
            _vehicles pushBack (_x call _fnc_serializeVehicle);
        };
        case (_x isKindOf "Thing");
        case (_x isKindOf "Static"): {
            _statics pushBack (_x call _fnc_serializeStatic);
        };
    };
} forEach _objects;

[_units, _vehicles, _statics, _groups]
