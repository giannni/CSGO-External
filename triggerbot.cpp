#include "stdafx.h"

void Triggerbot::triggerbot()
{
	const auto& crosshair_id = memory.read<uintptr_t>(offsets.local + offsets.m_iCrosshairId);

	// get our entity in the crosshair
	const auto& entity_incross = memory.read<uintptr_t>(offsets.client_base + offsets.dwEntityList + ((crosshair_id - 1) * 0x10));

	const auto& entity_team = memory.read<uintptr_t>(entity_incross + offsets.m_iTeamNum);

	const auto& entity_health = memory.read<uintptr_t>(entity_incross + offsets.m_iHealth);

	const auto& is_dormant = memory.read<uintptr_t>(entity_incross + offsets.m_bDormant);

	// check if crosshair is within the players
	if (crosshair_id <= 64 && crosshair_id > 0 && entity_team != offsets.local_team && entity_health > 0 && !is_dormant)
	{
		if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000)
		{
			// send mouse left down
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

			// delay
			//std::this_thread::sleep_for(std::chrono::milliseconds(10));

			// send mouse left up
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
}