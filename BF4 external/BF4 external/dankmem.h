#pragma once
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>




class Dankmem {
public:
	DWORD procID = this->GetProcID("bf4.exe");
	uintptr_t modBaseAddr = this->GetModuleAddr(procID, "bf4.exe");
	HANDLE procHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);

	DWORD GetProcID(const char* procName) {
		DWORD procID{};
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(PROCESSENTRY32);
		HANDLE hProcShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		if (hProcShot == INVALID_HANDLE_VALUE) {
			std::runtime_error{ "[!] Failed to take snapshot of processes.\n" };
			CloseHandle(hProcShot);
		}

		while (Process32Next(hProcShot, &procEntry)) {

			if (strcmp(procName, procEntry.szExeFile) == 0) {
				procID = procEntry.th32ProcessID;
			}
		}
		CloseHandle(hProcShot);
		return procID;
	}

	uintptr_t GetModuleAddr(DWORD processID, const char* modName) {
		
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(MODULEENTRY32);
		HANDLE hModShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processID);

		if (hModShot == INVALID_HANDLE_VALUE) {
			std::runtime_error{ "[!] Failed to take snapshot of modules.\n" };
			CloseHandle(hModShot);
		}
		while (Module32Next(hModShot, &modEntry)) {
			if (strcmp(modName, modEntry.szExePath) == 0) {

				if (hModShot == NULL) {
					std::runtime_error{ "Failed to get snapshot of module\n" };
					CloseHandle(hModShot);
					return false;
				}

				uintptr_t modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
				
			}
		}
		CloseHandle(hModShot);
		return modBaseAddr;
	}

	template<typename T>
	T rpm(uintptr_t lpBaseAddr) {
		T buffer{};
		ReadProcessMemory(procHandle, reinterpret_cast<LPCVOID>(lpBaseAddr), &buffer, sizeof(T), 0);
		return buffer;
	}

	template<typename T>
	T wpm(uintptr_t lpBaseAddr, T valueToWrite) {
		return WriteProcessMemory(procHandle, reinterpret_cast<LPVOID>(lpBaseAddr), &valueToWrite, sizeof(T), 0);
	}


};




	

	

	

