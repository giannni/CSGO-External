#include "stdafx.h"

void Triggerbot::triggerbot()
{
	// get our local player crosshair id
	const auto& crosshair_id = entity.get_crosshairid();

	// get our entity in the crosshair
	const auto& entity_incross = memory.read<uintptr_t>(offsets.client_base + offsets.dwEntityList + ((crosshair_id - 1) * 0x10));

	// check if crosshair is within the players
	if (crosshair_id <= 64 && crosshair_id > 0 && entity.is_valid(entity_incross))
	{
		if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000)
		{
			// send mouse left down
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

			// delay since we dont want full auto weapons to shoot super fast
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

			// send mouse left up
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
}