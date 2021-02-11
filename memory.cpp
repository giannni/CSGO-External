#include "stdafx.h"

// find the pid of our process
// credits to stackoverflow for this
bool Memory::GetProcess(const wchar_t* szName)
{
    if (auto hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0))
    {
        PROCESSENTRY32 ProcEntry;
        ProcEntry.dwSize = sizeof(ProcEntry);

        while (Process32Next(hProcess, &ProcEntry))
        {
            if (!wcscmp(ProcEntry.szExeFile, szName))
            {
                CloseHandle(hProcess);

                process.pid = ProcEntry.th32ProcessID;
                process.process_handle = OpenProcess(0x38, 0, process.pid);

                return true;
            }
        }

        CloseHandle(hProcess);
    }

    return false;
}

// get the modules from the process
// credits to stackoverflow for this
uintptr_t Memory::GetModule(const wchar_t* szModule)
{
    if (auto hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, process.pid))
    {
        MODULEENTRY32 ModEntry;
        ModEntry.dwSize = sizeof(ModEntry);

        while (Module32Next(hModule, &ModEntry))
        {
            if (!wcscmp(ModEntry.szModule, szModule))
            {
                CloseHandle(hModule);
                return reinterpret_cast<uintptr_t>(ModEntry.modBaseAddr);
            }
        }

        CloseHandle(hModule);
    }

    return 0x0;
}