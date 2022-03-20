#pragma once

Dankmem* mem = new Dankmem;
class Offsets {
public:
	
	DWORD64 OFFSET_ClientGameContext = mem->rpm<DWORD64>(mem->modBaseAddr + 0x142670d80);
	DWORD64 ClientManager = mem->rpm<DWORD64>(OFFSET_ClientGameContext + 0x60);
	DWORD64 LocalPlayer = mem->rpm<DWORD64>(ClientManager + 0x540);
	DWORD64 ClientSoldierEntity = mem->rpm<DWORD64>(LocalPlayer + 0x14D0);

	DWORD64 ClientSoldierWeaponsComponent = mem->rpm<DWORD64>(ClientSoldierEntity + 0x570);

	int ActiveSlot = mem->rpm<int>(ClientSoldierWeaponsComponent + 0xA98);

	DWORD64 CurrentAnimatedWeaponHandler = mem->rpm<DWORD64>(ClientSoldierWeaponsComponent + 0x890);

	DWORD64 ClientSoldierWeapon = mem->rpm<DWORD64>(CurrentAnimatedWeaponHandler + ActiveSlot * 0x8);

	DWORD64 ClientSoldierBreathControlComponent = mem->rpm<DWORD64>(ClientSoldierEntity + 0x588);

	DWORD64 HealthComponent = mem->rpm<DWORD64>(ClientSoldierEntity + 0x140);

	
};
