#include "stdafx.h"

uintptr_t Entity::get_engineptr()
{
	return memory.read<uintptr_t>(offsets.engine_base + offsets.dwClientState);
}

void Entity::force_update()
{
	memory.write<uintptr_t>(get_engineptr() + 0x16C, -1);
}

bool Entity::is_ingame()
{
	if (memory.read<uintptr_t>(get_engineptr() + offsets.dwClientState_State) == 6)
	{
		return true;
	}
	return false;
}

uintptr_t Entity::get_team(uintptr_t entity)
{
	return memory.read<uintptr_t>(entity + offsets.m_iTeamNum);
}

uintptr_t Entity::get_health(uintptr_t entity)
{
	return memory.read<uintptr_t>(entity + offsets.m_iHealth);
}

uintptr_t Entity::is_dormant(uintptr_t entity)
{
	return memory.read<uintptr_t>(entity + offsets.m_bDormant);
}

uintptr_t Entity::get_crosshairid()
{
	return memory.read<uintptr_t>(offsets.local + offsets.m_iCrosshairId);
}

D3DXVECTOR3 Entity::get_local_eyepos()
{
	D3DXVECTOR3 local_pos = entity.get_local_pos();
	local_pos += memory.read<D3DXVECTOR3>(offsets.local + offsets.m_vecViewOffset);
	return local_pos;
}

D3DXVECTOR3 Entity::get_local_pos()
{
	return memory.read<D3DXVECTOR3>(offsets.local + offsets.m_vecOrigin);
}

D3DXMATRIX Entity::get_local_matrix()
{
	return memory.read<D3DXMATRIX>(offsets.client_base + offsets.dwViewMatrix);
}

D3DXVECTOR3 Entity::get_local_view()
{
	return memory.read<D3DXVECTOR3>(get_engineptr() + offsets.dwClientState_ViewAngles);
}

void Entity::set_local_view(D3DXVECTOR3 angles)
{
	memory.write<D3DXVECTOR3>(get_engineptr() + offsets.dwClientState_ViewAngles, angles);
}

D3DXVECTOR3 Entity::get_local_punch()
{
	return memory.read<D3DXVECTOR3>(offsets.local + offsets.m_aimPunchAngle);
}

uintptr_t Entity::get_entbase(int index)
{
	return memory.read<uintptr_t>(offsets.client_base + offsets.dwEntityList + (index * 0x10));
}

bool Entity::is_alive(uintptr_t player_base)
{
	if (entity.get_health(player_base) > 0 && entity.get_health(player_base) <= 100)
		return true;
	return false;
}

bool Entity::is_valid(uintptr_t player_base)
{
	if ((entity.is_alive(player_base) && entity.get_team(player_base) != 0) && !entity.is_dormant(player_base))
		return true;
	return false;
}

D3DXVECTOR3	Entity::get_ent_pos(uintptr_t playerBase)
{
	return memory.read<D3DXVECTOR3>(playerBase + offsets.m_vecOrigin);
}

D3DXVECTOR3 Entity::get_ent_eye(uintptr_t player_base)
{
	return ((entity.get_ent_pos(player_base)) + (memory.read<D3DXVECTOR3>(player_base + offsets.m_vecViewOffset)));
}

uintptr_t Entity::get_ent_matrix(uintptr_t player_base)
{
	return memory.read<uintptr_t>(player_base + offsets.m_dwBoneMatrix);
}

D3DXVECTOR3	Entity::get_ent_bonepos(uintptr_t player_base, int bone_id)
{
	Matrix3x4_t boneMatrix = memory.read<Matrix3x4_t>(entity.get_ent_matrix(player_base) + bone_id * 0x30);

	return{
		boneMatrix.Matrix[0][3],
		boneMatrix.Matrix[1][3],
		boneMatrix.Matrix[2][3]
	};
}