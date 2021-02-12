#include "stdafx.h"

uintptr_t Aimbot::get_closest_target(float fov)
{
	D3DXVECTOR3 view_angles = entity.get_local_view();
	D3DXVECTOR3 local_eye_pos = entity.get_local_eyepos();

	uintptr_t best_entity;

	for (int i = 0; i < 64; i++)
	{
		if (entity.is_valid(entity.get_entbase(i)) && entity.get_team(entity.get_entbase(i)) != entity.get_team(offsets.local))
		{
			D3DXVECTOR3 angle = CalcAngle(local_eye_pos, entity.get_ent_bonepos(entity.get_entbase(i), 8));
			D3DXVECTOR3 clamped_angles = ClampAngles(angle - view_angles);
			float delta = sqrt(clamped_angles.x * clamped_angles.x + clamped_angles.y * clamped_angles.y);

			if (delta < fov)
			{
				fov = delta;
				best_entity = entity.get_entbase(i);
			}
		}
	}
	return best_entity;
}

void Aimbot::aim_at_target(uintptr_t player, int smooth, int bone)
{
	if (player != NULL)
	{
		D3DXVECTOR3 aim_angles = entity.get_ent_bonepos(player, bone) - entity.get_local_eyepos();
		VectorAngles(aim_angles, aim_angles);
		D3DXVECTOR3 delta = aim_angles - entity.get_local_view();
		D3DXVECTOR3 s_angles = ClampAngles(entity.get_local_view() + (delta / smooth));
		if (entity.is_valid(player))
			entity.set_local_view(s_angles);
	}
}

void Aimbot::aimbot()
{
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		aim_at_target(get_closest_target(100), 20, 8);
	}
}