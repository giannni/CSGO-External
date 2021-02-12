#include "stdafx.h"

void Radar::radar()
{
	// loop through entity list
	for (int i = 0; i <= 64; i++)
	{
		// get our entity
		auto enemy = entity.get_entbase(i);

		// check if the entity is spotted or not
		bool is_spotted = memory.read<bool>(enemy + offsets.m_bSpotted);

		if (entity.is_valid(enemy) && !is_spotted)
		{
			memory.write<bool>((uintptr_t)enemy + offsets.m_bSpotted, true);
		}
	}
}