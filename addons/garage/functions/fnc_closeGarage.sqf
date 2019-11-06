#include "script_component.hpp"
/*
 * Author: mharis001
 * Closes the garage display.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call zen_garage_fnc_closeGarage
 *
 * Public: No
 */

// Close the garage display
private _display = findDisplay IDD_DISPLAY;
_display closeDisplay 2;

GVAR(center) = nil;

// Remove tracking variables
GVAR(mouseButtons) = nil;
GVAR(interfaceShown) = nil;
GVAR(visionMode) = nil;

// Remove camera update handler
removeMissionEventHandler ["Draw3D", GVAR(camDraw3D)];
GVAR(camDraw3D) = nil;

// Delete camera helper
deleteVehicle GVAR(camHelper);
GVAR(camHelper) = nil;

// Return to zeus camera
GVAR(camera) cameraEffect ["terminate", "back"];
camDestroy GVAR(camera);

if (!isNull curatorCamera) then {
    GVAR(curatorCameraData) params ["_position", "_dirAndUp"];

    curatorCamera cameraEffect ["internal", "back"];
    curatorCamera setPosASL _position;
    curatorCamera setVectorDirAndUp _dirAndUp;
};

GVAR(camera) = nil;
