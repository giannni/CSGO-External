#include "stdafx.h"

void Radar::radar()
{
	// loop through entity list
	for (int i = 0; i <= 64; i++)
	{
		// get our entity
		const auto& entity = memory.read<uintptr_t>(offsets.client_base + offsets.entity_list + (i * 0x10));

		// check if the entity is spotted or not
		bool is_spotted = memory.read<bool>((uintptr_t)entity + offsets.spotted);

		if (!entity)
			return;

		const auto& entity_team = memory.read<uintptr_t>((uintptr_t)entity + offsets.team_num);

		const auto& entity_health = memory.read<uintptr_t>((uintptr_t)entity + offsets.health);

		if (entity_team != offsets.local_team)
		{
			if (entity_health > 0)
			{
				if (!is_spotted)
				{
					memory.write<bool>((uintptr_t)entity + offsets.spotted, true);
				}
			}
		}
	}
}