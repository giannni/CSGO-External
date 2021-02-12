#include "stdafx.h"

Triggerbot triggerbot;
Radar radar;
Aimbot aimbot;
Process process;
Memory memory;
Offsets offsets;
Entity entity;

int main()
{
	SetConsoleTitleW(L"CSGO External");

	// get our process, will always be csgo.exe unless valve changes something
	if (memory.GetProcess(L"csgo.exe"))
	{
		// get the module client.dll, could change but not very likely
		offsets.client_base = memory.GetModule(L"client.dll");
		printf("Client: 0x%" PRIXPTR "\n", (uintptr_t)offsets.client_base);

		// get the module engine.dll, could change but not very likely
		offsets.engine_base = memory.GetModule(L"engine.dll");
		printf("Engine: 0x%" PRIXPTR "\n", (uintptr_t)offsets.engine_base);

		// get our local player pointer
		offsets.local = memory.read<uintptr_t>(offsets.client_base + offsets.m_Local);
		printf("Local: 0x%" PRIXPTR "\n", (uintptr_t)offsets.local);

		// get our local player team pointer
		offsets.local_team = memory.read<uintptr_t>(offsets.local + offsets.m_iTeamNum);
		printf("Local Team: 0x%" PRIXPTR "\n", (uintptr_t)offsets.local_team);

		if (entity.is_ingame())
		{
			// infinite loop to keep updating our entity data and run our functions
			while (!(GetAsyncKeyState(VK_F10) & 0x01))
			{
				triggerbot.triggerbot();

				radar.radar();

				aimbot.aimbot();

				// sleep for 1 ms to give us better performance overall
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
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