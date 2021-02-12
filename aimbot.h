#include "stdafx.h"

struct Aimbot
{
	void aimbot();
	uintptr_t get_closest_target(float fov);
	void aim_at_target(uintptr_t player, int smooth, int bone);
};
extern Aimbot aimbot;