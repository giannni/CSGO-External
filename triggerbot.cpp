#include "stdafx.h"

void Triggerbot::triggerbot()
{
	if (offsets.local)
	{
		const auto& crosshair_id = memory.read<uintptr_t>((uintptr_t)offsets.local + offsets.crosshair_id);

		// get our entity in the crosshair
		const auto& entity = memory.read<uintptr_t>(offsets.client_base + offsets.entity_list + (crosshair_id - 1) * 0x10);

		if (!entity)
			return;

		const auto& entity_team = memory.read<uintptr_t>(entity + offsets.team_num);

		const auto& entity_health = memory.read<uintptr_t>(entity + offsets.health);

		// check if crosshair is within the players
		if (crosshair_id <= 64 && crosshair_id >= 0)
		{
			if (entity_team != offsets.local_team)
			{
				if (entity_health > 0)
				{
					if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000)
					{
						// send mouse left down
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

						// delay
						std::this_thread::sleep_for(std::chrono::milliseconds(10));

						// send mouse left up
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
				}
			}
		}
	}
}