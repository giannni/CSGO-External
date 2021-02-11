#include "stdafx.h"

// offsets dumped by hazedumper https://github.com/frk1/hazedumper/blob/master/csgo.hpp
struct Offsets
{
    uintptr_t client_base;
    uintptr_t engine_base;
    uintptr_t local;
    uintptr_t local_team;
    uintptr_t crosshair_id = 0xB3E4;
    uintptr_t spotted = 0x93D;
    uintptr_t team_num = 0xF4;
    uintptr_t life_state = 0x25F;
    uintptr_t health = 0x100;
    uintptr_t local_player = 0xD882BC;
    uintptr_t entity_list = 0x4D9FBD4;
    uintptr_t client_state = 0x58EFE4;
    uintptr_t client_state_state = 0x108;
    uintptr_t vec_origin = 0x138;
    uintptr_t vec_velocity = 0x114;
    uintptr_t vec_view_offset = 0x108;
    uintptr_t shots_fired = 0xA390;
    uintptr_t next_attack = 0x2D70;
    uintptr_t aim_punch_angle = 0x302C;
    uintptr_t aim_punch_angle_vel = 0x3038;
    uintptr_t eye_angles_x = 0xB37C;
    uintptr_t eye_angles_y = 0xB380;
    uintptr_t bone_matrix = 0x26A8;
    uintptr_t view_punch_angle = 0x3020;

};
extern Offsets offsets;

// our process
struct Process
{
    uintptr_t pid; // pid of the process
    HANDLE process_handle; // our process
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