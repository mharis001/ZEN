#include "script_component.hpp"
/*
 * Author: mharis001
 * Closes currently open context menu.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call zen_context_menu_fnc_closeMenu
 *
 * Public: No
 */

{
    ctrlDelete _x;
} forEach GVAR(contextGroups);

GVAR(contextGroups) = [];
