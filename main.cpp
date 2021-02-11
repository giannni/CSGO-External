#include "stdafx.h"

Offsets offsets;
Triggerbot triggerbot;
Radar radar;
Process process;
Memory memory;


bool is_in_game()
{
	const auto& engine_pointer = offsets.engine_base + offsets.client_state;

	if (memory.read<uintptr_t>((uintptr_t)engine_pointer + offsets.client_state_state) == 6)
	{
		return true;
	}
	return false;
}

int main()
{
	SetConsoleTitleW(L"CSGO External");

	// get our process, will always be csgo.exe unless valve changes something
	if (memory.GetProcess(L"csgo.exe"))
	{
		// get the module client.dll, could change but not very likely
		offsets.client_base = memory.GetModule(L"client.dll");

		// get the module engine.dll, could change but not very likely
		offsets.engine_base = memory.GetModule(L"engine.dll");

		if (is_in_game())
		{
			offsets.local = memory.read<uintptr_t>(offsets.client_base + offsets.local_player);

			if (offsets.local)
			{
				const auto& local_team = memory.read<uintptr_t>((uintptr_t)offsets.local + offsets.team_num);
			}

			// infinite loop to keep updating our entity data and run our functions
			while (!(GetAsyncKeyState(VK_F10) & 0x01))
			{
				triggerbot.triggerbot();

				radar.radar();

				// sleep for 1 ms to give us better performance overall
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
		else
		{
			wprintf(L"NOT IN GAME");
		}
	}
	else
	{
		wprintf(L"Couldn't find CSGO.EXE");
	}

	// close the handle to the process
	if (process.process_handle)
		CloseHandle(process.process_handle);

	// close the program successfully
	return EXIT_SUCCESS;
}