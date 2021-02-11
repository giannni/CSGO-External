#include "stdafx.h"

void Radar::radar()
{
	// loop through entity list
	for (int i = 0; i <= 64; i++)
	{
		// get our entity
		const auto& entity = memory.read<uintptr_t>(offsets.client_base + offsets.dwEntityList + (i * 0x10));

		// check if the entity is spotted or not
		bool is_spotted = memory.read<bool>(entity + offsets.m_bSpotted);

		const auto& entity_team = memory.read<uintptr_t>(entity + offsets.m_iTeamNum);

		const auto& entity_health = memory.read<uintptr_t>(entity + offsets.m_iHealth);

		if (entity_team != offsets.local_team && entity_health > 0 && !is_spotted)
		{
			memory.write<bool>((uintptr_t)entity + offsets.m_bSpotted, true);
		}
	}
}