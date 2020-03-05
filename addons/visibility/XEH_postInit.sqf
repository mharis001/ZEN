#include "script_component.hpp"

["zen_curatorDisplayLoaded", {
    if (GVAR(enabled)) then {
        call FUNC(start);
    };
}] call CBA_fnc_addEventHandler;

["zen_curatorDisplayUnloaded", {
    call FUNC(stop);
}] call CBA_fnc_addEventHandler;
