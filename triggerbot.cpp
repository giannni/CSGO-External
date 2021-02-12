#include "stdafx.h"

void Triggerbot::triggerbot()
{
	// get our local player crosshair id
	auto crosshair_id = entity.get_crosshairid();
	//printf("Crosshair id: 0x%" PRIXPTR "\n", (uintptr_t)crosshair_id);

	// get our entity in the crosshair
	auto entity_incross = entity.get_entity_incross();
	//printf("Entity Incross: 0x%" PRIXPTR "\n", (uintptr_t)entity_incross);

	//get our entity team from crosshair
	auto entity_team = entity.get_team(entity_incross);
	//printf("Entity Team: 0x%" PRIXPTR "\n", (uintptr_t)entity_team);

	// check if crosshair is within the players
	if (crosshair_id > 0 && crosshair_id <= 64)
	{
		if (offsets.local_team != entity_team && entity.is_valid(entity_incross))
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