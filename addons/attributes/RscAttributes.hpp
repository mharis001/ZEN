class RscText;
class RscEdit;
class ctrlToolbox;
class ctrlXSliderH;
class RscActivePicture;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscMapControl;
class RscButtonMenu;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCombo {
    class ComboScrollBar;
};

class GVAR(RscLabel): RscText {
    idc = -1;
    x = 0;
    y = 0;
    w = POS_W(10);
    h = POS_H(1);
    colorBackground[] = {0, 0, 0, 0.5};
};

class GVAR(RscBackground): RscText {
    idc = -1;
    style = ST_CENTER;
    x = POS_W(10);
    y = 0;
    w = POS_W(16);
    h = POS_H(2.5);
    colorText[] = {1, 1, 1, 0.5};
    colorBackground[] = COLOR_BACKGROUND_SETTING;
};

class GVAR(RscEdit): RscEdit {
    idc = -1;
    x = POS_W(10.1);
    y = pixelH;
    w = POS_W(15.9);
    h = POS_H(1) - pixelH;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0.2};
};

class GVAR(RscCombo): RscCombo {
    idc = -1;
    x = POS_W(10.1);
    y = 0;
    w = POS_W(15.9);
    h = POS_H(1);
    arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowFull_ca.paa";
    arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmpty_ca.paa";
    class ComboScrollBar: ComboScrollBar {
        thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
        border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
        arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
        arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
    };
};

class GVAR(RscAttributeName): RscControlsGroupNoScrollbars {
    idc = IDC_NAME;
    function = QFUNC(attributeName);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Object_Attribute_UnitName_displayName";
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_NAME_EDIT;
        };
    };
};

class GVAR(RscAttributeGroupID): RscControlsGroupNoScrollbars {
    idc = IDC_GROUPID;
    function = QFUNC(attributeGroupID);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_A3_RscAttributeGroupID_Title";
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_GROUPID_EDIT;
        };
    };
};

class GVAR(RscAttributePlateNumber): RscControlsGroupNoScrollbars {
    idc = IDC_PLATENUMBER;
    function = QFUNC(attributePlateNumber);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = CSTRING(PlateNumber);
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_PLATENUMBER_EDIT;
        };
    };
};

class GVAR(RscAttributeSkill): RscControlsGroupNoScrollbars {
    idc = IDC_SKILL;
    function = QFUNC(attributeSkill);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Object_Attribute_Skill_displayName";
        };
        class Slider: ctrlXSliderH {
            idc = IDC_SKILL_SLIDER;
            x = POS_W(10.1);
            y = 0;
            w = POS_W(13.5);
            h = POS_H(1);
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_SKILL_EDIT;
            x = POS_W(23.7);
            w = POS_W(2.3);
        };
    };
};

class GVAR(RscAttributeDamage): GVAR(RscAttributeSkill) {
    idc = IDC_DAMAGE;
    function = QFUNC(attributeDamage);
    class controls: controls {
        class Label: Label {
            text = "$STR_3DEN_Object_Attribute_Health_displayName";
        };
        class Slider: Slider {
            idc = IDC_DAMAGE_SLIDER;
        };
        class Edit: Edit {
            idc = IDC_DAMAGE_EDIT;
        };
    };
};

class GVAR(RscAttributeFuel): GVAR(RscAttributeSkill) {
    idc = IDC_FUEL;
    function = QFUNC(attributeFuel);
    class controls: controls {
        class Label: Label {
            text = "$STR_3DEN_Object_Attribute_Fuel_displayName";
        };
        class Slider: Slider {
            idc = IDC_FUEL_SLIDER;
        };
        class Edit: Edit {
            idc = IDC_FUEL_EDIT;
        };
    };
};

class GVAR(RscAttributeAmmo): GVAR(RscAttributeSkill) {
    idc = IDC_AMMO;
    function = QFUNC(attributeAmmo);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls: controls {
        class Label: Label {
            text = "$STR_3DEN_Object_Attribute_Ammo_displayName";
        };
        class Slider: Slider {
            idc = IDC_AMMO_SLIDER;
        };
        class Edit: Edit {
            idc = IDC_AMMO_EDIT;
        };
    };
};

class GVAR(RscAttributeLock): RscControlsGroupNoScrollbars {
    idc = IDC_LOCK;
    function = QFUNC(attributeLock);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Object_Attribute_Lock_displayName";
            h = POS_H(2);
        };
        class Toolbox: ctrlToolbox {
            idc = IDC_LOCK_TOOLBOX;
            x = POS_W(10.1);
            y = 0;
            w = POS_W(15.9);
            h = POS_H(2);
            rows = 2;
            columns = 2;
            strings[] = {
                "$STR_3DEN_Attributes_Lock_Locked_text",
                "$STR_3DEN_Attributes_Lock_Unlocked_text",
                "$STR_3DEN_Attributes_Lock_Default_text",
                "$STR_3DEN_Attributes_Lock_LockedForPlayer_text"
            };
            tooltips[] = {
                "$STR_3DEN_Attributes_Lock_Locked_tooltip",
                "$STR_3DEN_Attributes_Lock_Unlocked_tooltip",
                "$STR_3DEN_Attributes_Lock_Default_tooltip",
                "$STR_3DEN_Attributes_Lock_LockedForPlayer_tooltip"
            };
            values[] = {
                2,
                0,
                1,
                3
            };
        };
    };
};

class GVAR(RscAttributeEngine): RscControlsGroupNoScrollbars {
    idc = IDC_ENGINE;
    function = QFUNC(attributeEngine);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = CSTRING(Engine);
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class EngineOn: RscActivePicture {
            idc = IDC_ENGINE_ON;
            text = QPATHTOF(ui\engine_on_ca.paa);
            x = POS_W(14.5);
            y = POS_H(0.25);
            w = POS_W(2);
            h = POS_H(2);
        };
        class EngineOff: EngineOn {
            idc = IDC_ENGINE_OFF;
            text = QPATHTOF(ui\engine_off_ca.paa);
            x = POS_W(19.5);
        };
    };
};

class GVAR(RscAttributeLights): RscControlsGroupNoScrollbars {
    idc = IDC_LIGHTS;
    function = QFUNC(attributeLights);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = CSTRING(Lights);
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class LightsOn: RscActivePicture {
            idc = IDC_LIGHTS_ON;
            text = QPATHTOF(ui\lights_on_ca.paa);
            x = POS_W(14.5);
            y = POS_H(0.25);
            w = POS_W(2);
            h = POS_H(2);
        };
        class LightsOff: LightsOn {
            idc = IDC_LIGHTS_OFF;
            text = QPATHTOF(ui\lights_off_ca.paa);
            x = POS_W(19.5);
        };
    };
};

class GVAR(RscAttributeRank): RscControlsGroupNoScrollbars {
    idc = IDC_RANK;
    function = QFUNC(attributeRank);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Object_Attribute_Rank_displayName";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class Private: RscActivePicture {
            idc = IDC_RANK_PRIVATE;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\private_gs.paa";
            tooltip = "$STR_Private";
            x = POS_W(11.25);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
        class Corporal: Private {
            idc = IDC_RANK_CORPORAL;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
            tooltip = "$STR_Corporal";
            x = POS_W(13.25);
        };
        class Sergeant: Private {
            idc = IDC_RANK_SERGEANT;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
            tooltip = "$STR_Sergeant";
            x = POS_W(15.25);
        };
        class Lieutenant: Private {
            idc = IDC_RANK_LIEUTENANT;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa";
            tooltip = "$STR_Lieutenant";
            x = POS_W(17.25);
        };
        class Captain: Private {
            idc = IDC_RANK_CAPTAIN;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\captain_gs.paa";
            tooltip = "$STR_Captain";
            x = POS_W(19.25);
        };
        class Major: Private {
            idc = IDC_RANK_MAJOR;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa";
            tooltip = "$STR_Major";
            x = POS_W(21.25);
        };
        class Colonel: Private {
            idc = IDC_RANK_COLONEL;
            text = "\a3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
            tooltip = "$STR_Colonel";
            x = POS_W(23.25);
        };
    };
};

class GVAR(RscAttributeUnitPos): RscControlsGroupNoScrollbars {
    idc = IDC_UNITPOS;
    function = QFUNC(attributeUnitPos);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_A3_RscAttributeUnitPos_Title";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class Down: RscActivePicture {
            idc = IDC_UNITPOS_DOWN;
            text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_prone_ca.paa";
            tooltip = "$STR_A3_RscAttributeUnitPos_Down_tooltip";
            x = POS_W(13.25);
            y = 0;
            w = POS_W(2.5);
            h = POS_H(2.5);
        };
        class Crouch: Down {
            idc = IDC_UNITPOS_CROUCH;
            text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_crouch_ca.paa";
            tooltip = "$STR_A3_RscAttributeUnitPos_Crouch_tooltip";
            x = POS_W(15.75);
        };
        class Up: Down {
            idc = IDC_UNITPOS_UP;
            text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
            tooltip = "$STR_A3_RscAttributeUnitPos_Up_tooltip";
            x = POS_W(18.25);
        };
        class Auto: Down {
            idc = IDC_UNITPOS_AUTO;
            text = "\a3\ui_f_curator\Data\default_ca.paa";
            tooltip = "$STR_A3_RscAttributeUnitPos_Auto_tooltip";
            x = POS_W(24);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
    };
};

class GVAR(RscAttributeRespawnPosition): RscControlsGroupNoScrollbars {
    idc = IDC_RESPAWNPOSITION;
    function = QFUNC(attributeRespawnPosition);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_A3_RscAttributeRespawnPosition_Title";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {
            idc = IDC_RESPAWNPOSITION_BACKGROUND;
        };
        class West: RscActivePicture {
            idc = IDC_RESPAWNPOSITION_WEST;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\west_ca.paa";
            tooltip = "$STR_WEST";
            x = POS_W(11.5);
            y = POS_H(0.25);
            w = POS_W(2);
            h = POS_H(2);
        };
        class East: West {
            idc = IDC_RESPAWNPOSITION_EAST;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\east_ca.paa";
            tooltip = "$STR_EAST";
            x = POS_W(14.5);
        };
        class Guer: West {
            idc = IDC_RESPAWNPOSITION_GUER;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\guer_ca.paa";
            tooltip = "$STR_guerrila";
            x = POS_W(17.5);
        };
        class Civ: West {
            idc = IDC_RESPAWNPOSITION_CIV;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\civ_ca.paa";
            tooltip = "$STR_Civilian";
            x = POS_W(20.5);
        };
        class Disabled: West {
            idc = IDC_RESPAWNPOSITION_DISABLED;
            text = "\a3\Ui_F_Curator\Data\default_ca.paa";
            tooltip = "$STR_sensoractiv_none";
            x = POS_W(24);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
    };
};

class GVAR(RscAttributeExec): RscControlsGroupNoScrollbars {
    idc = IDC_EXEC;
    function = QFUNC(attributeExec);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_a3_rscdebugconsole_expressiontext";
            tooltip = CSTRING(Exec_Tooltip);
        };
        class History: GVAR(RscCombo) {
            idc = IDC_EXEC_HISTORY;
            font = "EtelkaMonospacePro";
            x = POS_W(10);
            w = POS_W(16);
            sizeEx = POS_H(0.65);
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_EXEC_EDIT;
            style = ST_MULTI;
            tooltip = CSTRING(Exec_Tooltip);
            font = "EtelkaMonospacePro";
            x = pixelW;
            y = POS_H(1);
            w = POS_W(26) - pixelW;
            h = POS_H(4);
            sizeEx = POS_H(0.65);
            autocomplete = "scripting";
        };
    };
};

class GVAR(RscAttributeFormation): RscControlsGroupNoScrollbars {
    idc = IDC_FORMATION;
    function = QFUNC(attributeFormation);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Group_Attribute_Formation_displayName";
            h = POS_H(5);
        };
        class Background: GVAR(RscBackground) {
            h = POS_H(5);
        };
        class Wedge: RscActivePicture {
            idc = IDC_FORMATION_WEDGE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\wedge_ca.paa";
            tooltip = "$STR_wedge";
            x = POS_W(11.75);
            y = 0;
            w = POS_W(2.5);
            h = POS_H(2.5);
        };
        class Vee: Wedge {
            idc = IDC_FORMATION_VEE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\vee_ca.paa";
            tooltip = "$STR_vee";
            x = POS_W(14.25);
        };
        class Line: Wedge {
            idc = IDC_FORMATION_LINE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\line_ca.paa";
            tooltip = "$STR_line";
            x = POS_W(16.75);
        };
        class Column: Wedge {
            idc = IDC_FORMATION_COLUMN;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\column_ca.paa";
            tooltip = "$STR_column";
            x = POS_W(19.25);
        };
        class File: Wedge {
            idc = IDC_FORMATION_FILE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\file_ca.paa";
            tooltip = "$STR_file";
            x = POS_W(21.75);
        };
        class StagColumn: Wedge {
            idc = IDC_FORMATION_STAGCOLUMN;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\stag_column_ca.paa";
            tooltip = "$STR_staggered";
            x = POS_W(11.75);
            y = POS_H(2.5);
        };
        class EchLeft: StagColumn {
            idc = IDC_FORMATION_ECHLEFT;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_left_ca.paa";
            tooltip = "$STR_echl";
            x = POS_W(14.25);
        };
        class EchRight: StagColumn {
            idc = IDC_FORMATION_ECHRIGHT;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_right_ca.paa";
            tooltip = "$STR_echr";
            x = POS_W(16.75);
        };
        class Diamond: StagColumn {
            idc = IDC_FORMATION_DIAMOND;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\diamond_ca.paa";
            tooltip = "$STR_diamond";
            x = POS_W(19.25);
        };
        class Default: StagColumn {
            idc = IDC_FORMATION_DEFAULT;
            text = "\a3\ui_f_curator\Data\default_ca.paa";
            tooltip = "$STR_no_change";
            x = POS_W(22.25);
            y = POS_H(3);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
    };
};

class GVAR(RscAttributeBehaviour): RscControlsGroupNoScrollbars {
    idc = IDC_BEHAVIOUR;
    function = QFUNC(attributeBehaviour);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Group_Attribute_Behaviour_displayName";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class Careless: RscActivePicture {
            idc = IDC_BEHAVIOUR_CARELESS;
            text = QPATHTOF(ui\careless_ca.paa);
            tooltip = "$STR_3DEN_Attributes_Behaviour_Careless_text";
            x = POS_W(11.25);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
        class Safe: Careless {
            idc = IDC_BEHAVIOUR_SAFE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\safe_ca.paa";
            tooltip = "$STR_safe";
            x = POS_W(13.75);
        };
        class Aware: Careless {
            idc = IDC_BEHAVIOUR_AWARE;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\aware_ca.paa";
            tooltip = "$STR_aware";
            x = POS_W(16.25);
        };
        class Combat: Careless {
            idc = IDC_BEHAVIOUR_COMBAT;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\combat_ca.paa";
            tooltip = "$STR_combat";
            x = POS_W(18.75);
        };
        class Stealth: Careless {
            idc = IDC_BEHAVIOUR_STEALTH;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\stealth_ca.paa";
            tooltip = "$STR_stealth";
            x = POS_W(21.25);
        };
        class Default: Careless {
            idc = IDC_BEHAVIOUR_DEFAULT;
            text = "\a3\ui_f_curator\Data\default_ca.paa";
            tooltip = "$STR_combat_unchanged";
            x = POS_W(24);
        };
    };
};

class GVAR(RscAttributeCombatMode): RscControlsGroupNoScrollbars {
    idc = IDC_COMBATMODE;
    function = QFUNC(attributeCombatMode);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Group_Attribute_CombatMode_displayName";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class Blue: RscActivePicture {
            idc = IDC_COMBATMODE_BLUE;
            text = QPATHTOF(ui\hold_ca.paa);
            tooltip = "$STR_3DEN_Attributes_CombatMode_Blue_text";
            x = POS_W(11.25);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
        class Green: Blue {
            idc = IDC_COMBATMODE_GREEN;
            text = QPATHTOF(ui\defend_ca.paa);
            tooltip = "$STR_3DEN_Attributes_CombatMode_Green_text";
            x = POS_W(13.75);
        };
        class White: Blue {
            idc = IDC_COMBATMODE_WHITE;
            text = QPATHTOF(ui\engage_ca.paa);
            tooltip = "$STR_3DEN_Attributes_CombatMode_White_text";
            x = POS_W(16.25);
        };
        class Yellow: Blue {
            idc = IDC_COMBATMODE_YELLOW;
            text = QPATHTOF(ui\hold_ca.paa);
            tooltip = "$STR_3DEN_Attributes_CombatMode_Yellow_text";
            x = POS_W(18.75);
        };
        class Red: Blue {
            idc = IDC_COMBATMODE_RED;
            text = QPATHTOF(ui\engage_ca.paa);
            tooltip = "$STR_3DEN_Attributes_CombatMode_Red_text";
            x = POS_W(21.25);
        };
        class Default: Blue {
            idc = IDC_COMBATMODE_DEFAULT;
            text = "\a3\ui_f_curator\Data\default_ca.paa";
            tooltip = "$STR_combat_unchanged";
            x = POS_W(24);
        };
    };
};

class GVAR(RscAttributeSpeedMode): RscControlsGroupNoScrollbars {
    idc = IDC_SPEEDMODE;
    function = QFUNC(attributeSpeedMode);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(2.5);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_HC_Menu_Speed";
            h = POS_H(2.5);
        };
        class Background: GVAR(RscBackground) {};
        class Limited: RscActivePicture {
            idc = IDC_SPEEDMODE_LIMITED;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\limited_ca.paa";
            tooltip = "$STR_speed_limited";
            x = POS_W(13.25);
            y = POS_H(0);
            w = POS_W(2.5);
            h = POS_H(2.5);
        };
        class Normal: Limited {
            idc = IDC_SPEEDMODE_NORMAL;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\normal_ca.paa";
            tooltip = "$STR_speed_normal";
            x = POS_W(15.75);
        };
        class Full: Limited {
            idc = IDC_SPEEDMODE_FULL;
            text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\full_ca.paa";
            tooltip = "$STR_speed_full";
            x = POS_W(18.25);
        };
        class Default: Limited {
            idc = IDC_SPEEDMODE_DEFAULT;
            text = "\a3\ui_f_curator\Data\default_ca.paa";
            tooltip = "$STR_speed_unchanged";
            x = POS_W(24);
            y = POS_H(0.5);
            w = POS_W(1.5);
            h = POS_H(1.5);
        };
    };
};

#define WAYPOINT_ROWS (ceil (count (uiNamespace getVariable 'GVAR(waypointTypes)') / 3))

class GVAR(RscAttributeWaypointType): RscControlsGroupNoScrollbars {
    idc = IDC_WAYPOINTTYPE;
    function = QFUNC(attributeWaypointType);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(WAYPOINT_ROWS + 1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Object_Attribute_Type_displayName";
            w = POS_W(26);
        };
        class Background: GVAR(RscBackground) {
            idc = IDC_WAYPOINTTYPE_BACKGROUND;
            x = 0;
            y = POS_H(1);
            w = POS_W(26);
            h = POS_H(WAYPOINT_ROWS);
        };
        class Toolbox: ctrlToolbox {
            idc = IDC_WAYPOINTTYPE_TOOLBOX;
            x = 0;
            y = POS_H(1);
            w = POS_W(26);
            h = POS_H(WAYPOINT_ROWS);
            colorBackground[] = {0, 0, 0, 0};
            tooltipColorBox[] = {0, 0, 0, 0};
            tooltipColorText[] = {0, 0, 0, 0};
            tooltipColorShade[] = {0, 0, 0, 0};
            rows = QUOTE(WAYPOINT_ROWS);
            columns = 3;
        };
    };
};

class GVAR(RscAttributeWaypointTimeout): GVAR(RscAttributeSkill) {
    idc = IDC_TIMEOUT;
    function = QFUNC(attributeWaypointTimeout);
    class controls: controls {
        class Label: Label {
            text = CSTRING(Timeout);
            tooltip = CSTRING(Timeout_Tooltip);
        };
        class Slider: Slider {
            idc = IDC_TIMEOUT_SLIDER;
        };
        class Edit: Edit {
            idc = IDC_TIMEOUT_EDIT;
        };
    };
};

class GVAR(RscAttributeMarkerText): RscControlsGroupNoScrollbars {
    idc = IDC_MARKERTEXT;
    function = QFUNC(attributeMarkerText);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Marker_Attribute_Text_displayName";
        };
        class Edit: GVAR(RscEdit) {
            idc = IDC_MARKERTEXT_EDIT;
        };
    };
};

class GVAR(RscAttributeMarkerColor): RscControlsGroupNoScrollbars {
    idc = IDC_MARKERCOLOR;
    function = QFUNC(attributeMarkerColor);
    x = 0;
    y = 0;
    w = POS_W(26);
    h = POS_H(1);
    class controls {
        class Label: GVAR(RscLabel) {
            text = "$STR_3DEN_Marker_Attribute_Color_displayName";
        };
        class Combo: GVAR(RscCombo) {
            idc = IDC_MARKERCOLOR_COMBO;
        };
    };
};

class GVAR(RscAttributesBase) {
    idd = -1;
    class controls {
        class Title: RscText {
            idc = IDC_TITLE;
            x = POS_X(6.5);
            y = POS_Y(8.4);
            w = POS_W(27);
            h = POS_H(1);
            colorBackground[] = GUI_THEME_COLOR;
        };
        class Background: RscText {
            idc = IDC_BACKGROUND;
            x = POS_X(6.5);
            y = POS_Y(9.5);
            w = POS_W(27);
            h = POS_H(6.5);
            colorBackground[] = {0, 0, 0, 0.7};
        };
        class Content: RscControlsGroup {
            idc = IDC_CONTENT;
            x = POS_X(7);
            y = POS_Y(10);
            w = POS_W(26);
            h = POS_H(5.5);
        };
        class ButtonOK: RscButtonMenuOK {
            x = POS_X(28.5);
            y = POS_Y(16.1);
            w = POS_W(5);
            h = POS_H(1);
        };
        class ButtonCancel: RscButtonMenuCancel {
            x = POS_X(6.5);
            y = POS_Y(16.1);
            w = POS_W(5);
            h = POS_H(1);
        };
    };
};

class GVAR(RscAttributesMan): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesMan))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class Name: GVAR(RscAttributeName) {};
                class Skill: GVAR(RscAttributeSkill) {};
                class Damage: GVAR(RscAttributeDamage) {};
                class Rank: GVAR(RscAttributeRank) {};
                class UnitPos: GVAR(RscAttributeUnitPos) {};
                class RespawnPosition: GVAR(RscAttributeRespawnPosition) {};
                class Exec: GVAR(RscAttributeExec) {};
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
    class Buttons {
        class Arsenal {
            text = "$STR_A3_Arsenal";
            function = QFUNC(buttonArsenal);
        };
        class Skills {
            text = CSTRING(Skills);
            function = QFUNC(buttonSkills);
        };
        class Traits {
            text = CSTRING(Traits);
            function = QFUNC(buttonTraits);
        };
    };
};

class GVAR(RscAttributesVehicle): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesVehicle))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class Skill: GVAR(RscAttributeSkill) {};
                class Damage: GVAR(RscAttributeDamage) {};
                class Fuel: GVAR(RscAttributeFuel) {};
                class Ammo: GVAR(RscAttributeAmmo) {};
                class Rank: GVAR(RscAttributeRank) {};
                class Lock: GVAR(RscAttributeLock) {};
                class Engine: GVAR(RscAttributeEngine) {};
                class Lights: GVAR(RscAttributeLights) {};
                class PlateNumber: GVAR(RscAttributePlateNumber) {};
                class RespawnPosition: GVAR(RscAttributeRespawnPosition) {};
                class Exec: GVAR(RscAttributeExec) {};
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
    class Buttons {
        class Sensors {
            text = CSTRING(Sensors);
            function = QFUNC(buttonSensors);
        };
        class Components {
            text = CSTRING(Components);
            function = QFUNC(buttonComponents);
        };
    };
};

class GVAR(RscAttributesVehicleEmpty): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesVehicleEmpty))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class Damage: GVAR(RscAttributeDamage) {};
                class Fuel: GVAR(RscAttributeFuel) {};
                class Ammo: GVAR(RscAttributeAmmo) {};
                class Lock: GVAR(RscAttributeLock) {};
                class Engine: GVAR(RscAttributeEngine) {};
                class Lights: GVAR(RscAttributeLights) {};
                class PlateNumber: GVAR(RscAttributePlateNumber) {};
                class RespawnPosition: GVAR(RscAttributeRespawnPosition) {};
                class Exec: GVAR(RscAttributeExec) {};
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
    class Buttons {
        class Sensors {
            text = CSTRING(Sensors);
            function = QFUNC(buttonSensors);
        };
        class Components {
            text = CSTRING(Components);
            function = QFUNC(buttonComponents);
        };
    };
};

class GVAR(RscAttributesGroup): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesGroup))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class GroupID: GVAR(RscAttributeGroupID) {};
                class Skill: GVAR(RscAttributeSkill) {};
                class Formation: GVAR(RscAttributeFormation) {};
                class Behaviour: GVAR(RscAttributeBehaviour) {
                    class controls: controls {
                        class Label: Label {};
                        class Background: Background {};
                        class Careless : Careless {
                            x = POS_W(12.25);
                        };
                        class Safe : Safe {
                            x = POS_W(14.75);
                        };
                        class Aware : Aware {
                            x = POS_W(17.25);
                        };
                        class Combat : Combat {
                            x = POS_W(19.75);
                        };
                        class Stealth : Stealth {
                            x = POS_W(22.25);
                        };
                        class Default : Default {};
                    };
                };
                class CombatMode: GVAR(RscAttributeCombatMode) {
                    class controls: controls {
                        class Label: Label {};
                        class Background: Background {};
                        class Blue: Blue {
                            x = POS_W(12.25);
                        };
                        class Green: Green {
                            x = POS_W(14.75);
                        };
                        class White: White {
                            x = POS_W(17.25);
                        };
                        class Yellow: Yellow {
                            x = POS_W(19.75);
                        };
                        class Red: Red {
                            x = POS_W(22.25);
                        };
                        class Default: Default {};
                    };
                };
                class SpeedMode: GVAR(RscAttributeSpeedMode) {
                    class controls: controls {
                        class Label: Label {};
                        class Background: Background {};
                        class Limited: Limited {
                            x = POS_W(14.25);
                        };
                        class Normal: Normal {
                            x = POS_W(16.75);
                        };
                        class Full: Full {
                            x = POS_W(19.25);
                        };
                        class Default: Default {};
                    };
                };
                class UnitPos: GVAR(RscAttributeUnitPos) {
                    class controls: controls {
                        class Label: Label {};
                        class Background: Background {};
                        class Down: Down {
                            x = POS_W(14.25);
                        };
                        class Crouch: Crouch {
                            x = POS_W(16.75);
                        };
                        class Up: Up {
                            x = POS_W(19.25);
                        };
                        class Auto: Auto {};
                    };
                };
                class RespawnPosition: GVAR(RscAttributeRespawnPosition) {
                    class controls: controls {
                        class Label: Label {
                            text = "$STR_A3_RscAttributeRespawnPosition_TitleGroup";
                        };
                        class Background: Background {};
                        class West: West {};
                        class East: East {};
                        class Guer: Guer {};
                        class Civ: Civ {};
                        class Disabled: Disabled {};
                    };
                };
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
    class Buttons {
        class Skills {
            text = CSTRING(Skills);
            function = QFUNC(buttonSkills);
        };
        class Side {
            text = ECSTRING(common,Side);
            function = QFUNC(buttonSide);
        };
    };
};

class GVAR(RscAttributesWaypoint): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesWaypoint))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class WaypointType: GVAR(RscAttributeWaypointType) {};
                class WaypointTimeout: GVAR(RscAttributeWaypointTimeout) {};
                class Formation: GVAR(RscAttributeFormation) {};
                class Behaviour: GVAR(RscAttributeBehaviour) {};
                class CombatMode: GVAR(RscAttributeCombatMode) {};
                class SpeedMode: GVAR(RscAttributeSpeedMode) {};
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};

class GVAR(RscAttributesMarker): GVAR(RscAttributesBase) {
    onLoad = QUOTE([ARR_2(_this select 0, QQGVAR(RscAttributesMarker))] call FUNC(initAttributesDisplay));
    filterAttributes = 1;
    class controls: controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class MarkerText: GVAR(RscAttributeMarkerText) {};
                class MarkerColor: GVAR(RscAttributeMarkerColor) {};
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
