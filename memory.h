#include "stdafx.h"

// offsets dumped by hazedumper https://github.com/frk1/hazedumper/blob/master/csgo.hpp

struct Offsets 
{
    uintptr_t client_base;
    uintptr_t engine_base;
    uintptr_t local;
    uintptr_t local_team;

    //netvars
    uintptr_t cs_gamerules_data = 0x0;
    uintptr_t m_ArmorValue = 0xB378;
    uintptr_t m_Collision = 0x320;
    uintptr_t m_CollisionGroup = 0x474;
    uintptr_t m_Local = 0x2FBC;
    uintptr_t m_MoveType = 0x25C;
    uintptr_t m_OriginalOwnerXuidHigh = 0x31C4;
    uintptr_t m_OriginalOwnerXuidLow = 0x31C0;
    uintptr_t m_SurvivalGameRuleDecisionTypes = 0x1328;
    uintptr_t m_SurvivalRules = 0xD00;
    uintptr_t m_aimPunchAngle = 0x302C;
    uintptr_t m_aimPunchAngleVel = 0x3038;
    uintptr_t m_angEyeAnglesX = 0xB37C;
    uintptr_t m_angEyeAnglesY = 0xB380;
    uintptr_t m_bBombPlanted = 0x9A5;
    uintptr_t m_bFreezePeriod = 0x20;
    uintptr_t m_bGunGameImmunity = 0x3944;
    uintptr_t m_bHasDefuser = 0xB388;
    uintptr_t m_bHasHelmet = 0xB36C;
    uintptr_t m_bInReload = 0x32A5;
    uintptr_t m_bIsDefusing = 0x3930;
    uintptr_t m_bIsQueuedMatchmaking = 0x74;
    uintptr_t m_bIsScoped = 0x3928;
    uintptr_t m_bIsValveDS = 0x7C;
    uintptr_t m_bSpotted = 0x93D;
    uintptr_t m_bSpottedByMask = 0x980;
    uintptr_t m_bStartedArming = 0x33F0;
    uintptr_t m_bUseCustomAutoExposureMax = 0x9D9;
    uintptr_t m_bUseCustomAutoExposureMin = 0x9D8;
    uintptr_t m_bUseCustomBloomScale = 0x9DA;
    uintptr_t m_clrRender = 0x70;
    uintptr_t m_dwBoneMatrix = 0x26A8;
    uintptr_t m_fAccuracyPenalty = 0x3330;
    uintptr_t m_fFlags = 0x104;
    uintptr_t m_flC4Blow = 0x2990;
    uintptr_t m_flCustomAutoExposureMax = 0x9E0;
    uintptr_t m_flCustomAutoExposureMin = 0x9DC;
    uintptr_t m_flCustomBloomScale = 0x9E4;
    uintptr_t m_flDefuseCountDown = 0x29AC;
    uintptr_t m_flDefuseLength = 0x29A8;
    uintptr_t m_flFallbackWear = 0x31D0;
    uintptr_t m_flFlashDuration = 0xA420;
    uintptr_t m_flFlashMaxAlpha = 0xA41C;
    uintptr_t m_flLastBoneSetupTime = 0x2924;
    uintptr_t m_flLowerBodyYawTarget = 0x3A90;
    uintptr_t m_flNextAttack = 0x2D70;
    uintptr_t m_flNextPrimaryAttack = 0x3238;
    uintptr_t m_flSimulationTime = 0x268;
    uintptr_t m_flTimerLength = 0x2994;
    uintptr_t m_hActiveWeapon = 0x2EF8;
    uintptr_t m_hMyWeapons = 0x2DF8;
    uintptr_t m_hObserverTarget = 0x338C;
    uintptr_t m_hOwner = 0x29CC;
    uintptr_t m_hOwnerEntity = 0x14C;
    uintptr_t m_iAccountID = 0x2FC8;
    uintptr_t m_iClip1 = 0x3264;
    uintptr_t m_iCompetitiveRanking = 0x1A84;
    uintptr_t m_iCompetitiveWins = 0x1B88;
    uintptr_t m_iCrosshairId = 0xB3E4;
    uintptr_t m_iDefaultFOV = 0x332C;
    uintptr_t m_iEntityQuality = 0x2FAC;
    uintptr_t m_iFOVStart = 0x31E8;
    uintptr_t m_iGlowIndex = 0xA438;
    uintptr_t m_iHealth = 0x100;
    uintptr_t m_iItemDefinitionIndex = 0x2FAA;
    uintptr_t m_iItemIDHigh = 0x2FC0;
    uintptr_t m_iMostRecentModelBoneCounter = 0x2690;
    uintptr_t m_iObserverMode = 0x3378;
    uintptr_t m_iShotsFired = 0xA390;
    uintptr_t m_iState = 0x3258;
    uintptr_t m_iTeamNum = 0xF4;
    uintptr_t m_lifeState = 0x25F;
    uintptr_t m_nFallbackPaintKit = 0x31C8;
    uintptr_t m_nFallbackSeed = 0x31CC;
    uintptr_t m_nFallbackStatTrak = 0x31D4;
    uintptr_t m_nForceBone = 0x268C;
    uintptr_t m_nTickBase = 0x3430;
    uintptr_t m_rgflCoordinateFrame = 0x444;
    uintptr_t m_szCustomName = 0x303C;
    uintptr_t m_szLastPlaceName = 0x35B4;
    uintptr_t m_thirdPersonViewAngles = 0x31D8;
    uintptr_t m_vecOrigin = 0x138;
    uintptr_t m_vecVelocity = 0x114;
    uintptr_t m_vecViewOffset = 0x108;
    uintptr_t m_viewPunchAngle = 0x3020;

    //signatures
    uintptr_t anim_overlays = 0x2980;
    uintptr_t clientstate_choked_commands = 0x4D30;
    uintptr_t clientstate_delta_ticks = 0x174;
    uintptr_t clientstate_last_outgoing_command = 0x4D2C;
    uintptr_t clientstate_net_channel = 0x9C;
    uintptr_t convar_name_hash_table = 0x2F0F8;
    uintptr_t dwClientState = 0x58EFE4;
    uintptr_t dwClientState_GetLocalPlayer = 0x180;
    uintptr_t dwClientState_IsHLTV = 0x4D48;
    uintptr_t dwClientState_Map = 0x28C;
    uintptr_t dwClientState_MapDirectory = 0x188;
    uintptr_t dwClientState_MaxPlayer = 0x388;
    uintptr_t dwClientState_PlayerInfo = 0x52C0;
    uintptr_t dwClientState_State = 0x108;
    uintptr_t dwClientState_ViewAngles = 0x4D90;
    uintptr_t dwEntityList = 0x4DA2F44;
    uintptr_t dwForceAttack = 0x31D44D4;
    uintptr_t dwForceAttack2 = 0x31D44E0;
    uintptr_t dwForceBackward = 0x31D448C;
    uintptr_t dwForceForward = 0x31D44F8;
    uintptr_t dwForceJump = 0x524CEA4;
    uintptr_t dwForceLeft = 0x31D4480;
    uintptr_t dwForceRight = 0x31D44A4;
    uintptr_t dwGameDir = 0x62D7F8;
    uintptr_t dwGameRulesProxy = 0x52C018C;
    uintptr_t dwGetAllClasses = 0xDB2F8C;
    uintptr_t dwGlobalVars = 0x58ECE8;
    uintptr_t dwGlowObjectManager = 0x52EB540;
    uintptr_t dwInput = 0x51F4528;
    uintptr_t dwInterfaceLinkList = 0x9457A4;
    uintptr_t dwLocalPlayer = 0xD8B2BC;
    uintptr_t dwMouseEnable = 0xD90E60;
    uintptr_t dwMouseEnablePtr = 0xD90E30;
    uintptr_t dwPlayerResource = 0x31D2800;
    uintptr_t dwRadarBase = 0x51D7CBC;
    uintptr_t dwSensitivity = 0xD90CFC;
    uintptr_t dwSensitivityPtr = 0xD90CD0;
    uintptr_t dwSetClanTag = 0x8A1A0;
    uintptr_t dwViewMatrix = 0x4D94844;
    uintptr_t dwWeaponTable = 0x51F4FE8;
    uintptr_t dwWeaponTableIndex = 0x325C;
    uintptr_t dwYawPtr = 0xD90AC0;
    uintptr_t dwZoomSensitivityRatioPtr = 0xD95D60;
    uintptr_t dwbSendPackets = 0xD73EA;
    uintptr_t dwppDirect3DDevice9 = 0xA7050;
    uintptr_t find_hud_element = 0x2E15E320;
    uintptr_t force_update_spectator_glow = 0x3AD962;
    uintptr_t interface_engine_cvar = 0x3E9EC;
    uintptr_t is_c4_owner = 0x3BA430;
    uintptr_t m_bDormant = 0xED;
    uintptr_t m_flSpawnTime = 0xA370;
    uintptr_t m_pStudioHdr = 0x294C;
    uintptr_t m_pitchClassPtr = 0x51D7F58;
    uintptr_t m_yawClassPtr = 0xD90AC0;
    uintptr_t model_ambient_min = 0x59205C;
    uintptr_t set_abs_angles = 0x1DF9C0;
    uintptr_t set_abs_origin = 0x1DF800;
};
extern Offsets offsets;

// our process
struct Process
{
    uintptr_t pid = 0; // pid of the process
    HANDLE process_handle = 0; // our process
};
extern Process process;

// our memory read and write functions
struct Memory
{
    bool GetProcess(const wchar_t* szName);
    uintptr_t GetModule(const wchar_t* szModule);

    template<class type>
    type read(uintptr_t address_to_read)
    {
        type data;
        ReadProcessMemory(process.process_handle, reinterpret_cast<LPVOID>(address_to_read), &data, sizeof(type), 0);
        return data;
    }

    template <class type>
    void write(uintptr_t address_to_write, type value_to_write)
    {
        WriteProcessMemory(process.process_handle, reinterpret_cast<LPVOID>(address_to_write), &value_to_write, sizeof(value_to_write), NULL);
    }
};
extern Memory memory;