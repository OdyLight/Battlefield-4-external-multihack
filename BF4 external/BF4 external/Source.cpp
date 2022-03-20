#include <vector>
#include "dankmem.h"
#include "offsets.h"

#define whiteColor 15
#define blueColor 9
#define redColor 4
#define greenColor 10
#define arrowColor 15
#define PTRMAXVAL ((PVOID)0x000F000000000000)




HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

bool bIsSubIndex, bNoRecoil, bNoSpread, bNoBreath, bDamageHack, bNoBulletdrop, bROF, bInstantHit, bNoVegetaion, bSunLightEnabled = false;

enum class WeaponSlot {
	m_primary = 0,
	m_secondary = 1,
	m_gadget = 2,
	m_grenade = 6,
	m_knife = 7
};

enum class MenuIndex {
	m_minIndex = 0,
	m_noRecoil = 1,
	m_noSpread = 2,
	m_noBreath = 3,
	m_noBulletdrop = 4,
	m_RateofFire = 5,
	m_damageHack = 6,
	m_instantHit = 7,
	m_noVegetation = 8,
	m_maxIndex = 9
};


class MenuText {
public:
	void setTextColor(WORD color) {
		SetConsoleTextAttribute(hConsole, color);
	}
	void update_mainIndexes() {
		system("cls");
		print_procStatus();
		print_main_noRecoil();
		print_main_noSpread();
		print_main_noBreath();
		print_main_noBulletdrop();
		print_main_RateofFire();
		print_main_Damagehack();
		print_main_InstantHit();
		print_main_NoVegetation();
	}

	void update_subIndexes() {
		system("cls");
		print_procStatus();
		print_sub_noRecoil();
		print_sub_noSpread();
		print_sub_noBreath();
		print_sub_noBulletdrop();
		print_sub_RateofFire();
		print_sub_Damagehack();
		print_sub_InstantHit();
		print_sub_NoVegetation();
	}

	void print_procStatus() {
		while (!(mem->GetProcID("bf4.exe"))) {
			setTextColor(blueColor);
			std::cout << "Game status -> ";
			setTextColor(redColor);
			std::cout << "Waiting for game...\n";
			std::cout << "\n\n";
			Sleep(1000);
			system("cls");
		}
		if ((mem->GetProcID("bf4.exe"))) {
			setTextColor(blueColor);
			std::cout << "Game status -> ";
			setTextColor(greenColor);
			std::cout << "Running\n";
			std::cout << "\n\n";
		}
	}


	void print_mainIndexes() {
		print_procStatus();
		print_main_noRecoil();
		print_main_noSpread();
		print_main_noBreath();
		print_main_noBulletdrop();
		print_main_RateofFire();
		print_main_Damagehack();
		print_main_InstantHit();
		print_main_NoVegetation();
	}

	

	void print_main_noRecoil() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_noRecoil) {
				setTextColor(whiteColor);
				std::cout << "[+] No Recoil\t\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] No Recoil\t\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_noRecoil() {

		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_noRecoil && noRecoilSubIndex == 0 && bNoRecoil == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Recoil\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noRecoil && noRecoilSubIndex == 1 && bNoRecoil == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Recoil\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noRecoil && noRecoilSubIndex == 0 && bNoRecoil == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Recoil\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noRecoil && noRecoilSubIndex == 1 && bNoRecoil == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Recoil\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}
		
	
	void print_main_noSpread() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_noSpread) {
				setTextColor(whiteColor);
				std::cout << "[+] No Spread\t\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] No Spread\t\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_noSpread() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_noSpread && noSpreadSubIndex == 0 && bNoSpread == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Spread\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noSpread && noSpreadSubIndex == 1 && bNoSpread == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Spread\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noSpread && noSpreadSubIndex == 0 && bNoSpread == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Spread\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noSpread && noSpreadSubIndex == 1 && bNoSpread == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Spread\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_noBreath() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_noBreath) {
				setTextColor(whiteColor);
				std::cout << "[+] No Breath\t\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] No Breath\t\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_noBreath() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_noBreath && noBreathSubIndex == 0 && bNoBreath == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Breath\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBreath && noBreathSubIndex == 1 && bNoBreath == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Breath\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBreath && noBreathSubIndex == 0 && bNoBreath == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Breath\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBreath && noBreathSubIndex == 1 && bNoBreath == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Breath\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_noBulletdrop() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_noBulletdrop) {
				setTextColor(whiteColor);
				std::cout << "[+] No Bulletdrop\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] No Bulletdrop\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_noBulletdrop() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_noBulletdrop && noBulletdropSubIndex == 0 && bNoBulletdrop == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Bullet Drop\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBulletdrop && noBulletdropSubIndex == 1 && bNoBulletdrop == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Bullet Drop\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBulletdrop && noBulletdropSubIndex == 0 && bNoBulletdrop == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Bullet Drop\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noBulletdrop && noBulletdropSubIndex == 1 && bNoBulletdrop == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Bullet Drop\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_RateofFire() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_RateofFire) {
				setTextColor(whiteColor);
				std::cout << "[+] Rate of fire\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] Rate of fire\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_RateofFire() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_RateofFire && rofSubindex == 0 && bROF == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Rate of fire\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_RateofFire && rofSubindex == 1 && bROF == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Rate of fire\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_RateofFire && rofSubindex == 0 && bROF == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Rate of fire\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_RateofFire && rofSubindex == 1 && bROF == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Rate of fire\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_Damagehack() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_damageHack) {
				setTextColor(whiteColor);
				std::cout << "[+] Damage hack\t\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] Damage hack\t\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_Damagehack() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_damageHack && damageSubIndex == 0 && bDamageHack == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Projectile damage\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_damageHack && damageSubIndex == 1 && bDamageHack == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Projectile damage\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_damageHack && damageSubIndex == 0 && bDamageHack == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Projectile damage\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_damageHack && damageSubIndex == 1 && bDamageHack == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Projectile damage\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_InstantHit() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_instantHit) {
				setTextColor(whiteColor);
				std::cout << "[+] Instant hit\t\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] Instant hit\t\t";
				std::cout << ">>" << std::endl;
			}
		}
	}
	
	void print_sub_InstantHit() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_instantHit && instanthitSubIndex == 0 && bInstantHit == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Instant hit\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_instantHit && instanthitSubIndex == 1 && bInstantHit == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Instant hit\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_instantHit && instanthitSubIndex == 0 && bInstantHit == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Instant hit\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_instantHit && instanthitSubIndex == 1 && bInstantHit == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "Instant hit\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	void print_main_NoVegetation() {
		if (bIsSubIndex == false) {
			if (currentMainIndex == (size_t)MenuIndex::m_noVegetation) {
				setTextColor(whiteColor);
				std::cout << "[+] No Vegetation\t";
				setTextColor(arrowColor);
				std::cout << ">>" << std::endl;
				setTextColor(blueColor);
			}
			else {
				setTextColor(blueColor);
				std::cout << "[+] No Vegetation\t";
				std::cout << ">>" << std::endl;
			}
		}
	}

	void print_sub_NoVegetation() {
		if (bIsSubIndex == true) {
			if (currentMainIndex == (size_t)MenuIndex::m_noVegetation && noVegetationSubIndex == 0 && bNoVegetaion == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Vegetation\n\n\n";
				setTextColor(whiteColor);
				std::cout << ">>ON<<\n";
				setTextColor(redColor);
				std::cout << "OFF\n" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noVegetation && noVegetationSubIndex == 1 && bNoVegetaion == true) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Vegetation\n\n\n";
				setTextColor(greenColor);
				std::cout << ">>ON<<\n";
				setTextColor(whiteColor);
				std::cout << "OFF" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noVegetation && noVegetationSubIndex == 0 && bNoVegetaion == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Vegetation\n\n\n";
				setTextColor(whiteColor);
				std::cout << "ON\n";
				setTextColor(greenColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
			else if (currentMainIndex == (size_t)MenuIndex::m_noVegetation && noVegetationSubIndex == 1 && bNoVegetaion == false) {
				system("cls");
				setTextColor(blueColor);
				std::cout << "Current index -> ";
				setTextColor(greenColor);
				std::cout << "No Vegetation\n\n\n";
				setTextColor(redColor);
				std::cout << "ON\n";
				setTextColor(whiteColor);
				std::cout << ">>OFF<<" << std::endl;
				setTextColor(blueColor);
			}
		}
	}

	size_t currentMainIndex{ 0 };
	size_t noRecoilSubIndex{ 0 };
	size_t noSpreadSubIndex{ 0 };
	size_t noBreathSubIndex{ 0 };
	size_t noBulletdropSubIndex{ 0 };
	size_t rofSubindex{ 0 };
	size_t damageSubIndex{ 0 };
	size_t instanthitSubIndex{ 0 };
	size_t noVegetationSubIndex{ 0 };
private:
	
};


class MenuControl : MenuText {
public:

	void navigate_mainIndexes() {

		switch (currentMainIndex) {

		case ((size_t)MenuIndex::m_minIndex): {
			currentMainIndex++;
			update_mainIndexes();
			break;
		}

		case ((size_t)MenuIndex::m_noRecoil): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_noRecoil();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noSpread): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_noSpread();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noBreath): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_noBreath();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noBulletdrop): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_noBulletdrop();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_RateofFire): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_RateofFire();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_damageHack): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_Damagehack();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case((size_t)MenuIndex::m_instantHit): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_InstantHit();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case((size_t)MenuIndex::m_noVegetation): {

			if (bIsSubIndex == false) {

				if (GetAsyncKeyState(VK_NUMPAD6) & 1) {
					bIsSubIndex = true;
					print_sub_NoVegetation();
				}

				else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					currentMainIndex++;
					update_mainIndexes();
				}

				else if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					currentMainIndex--;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_maxIndex): {
			currentMainIndex--;
			update_mainIndexes();
			break;
		}
		}
	}
	
	void navigate_subIndexes() {

		switch (currentMainIndex) {

		case ((size_t)MenuIndex::m_noRecoil): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					noRecoilSubIndex++;
					if (noRecoilSubIndex > 1) noRecoilSubIndex--;
					print_sub_noRecoil();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					noRecoilSubIndex--;
					if (noRecoilSubIndex < 0) noRecoilSubIndex++;
					print_sub_noRecoil();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bNoRecoil = !bNoRecoil;
					print_sub_noRecoil();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();

				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noSpread): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					noSpreadSubIndex++;
					if (noSpreadSubIndex > 1) noSpreadSubIndex--;
					print_sub_noSpread();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					noSpreadSubIndex--;
					if (noSpreadSubIndex < 0) noSpreadSubIndex++;
					print_sub_noSpread();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bNoSpread = !bNoSpread;
					print_sub_noSpread();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noBreath): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					noBreathSubIndex++;
					if (noBreathSubIndex > 1) noBreathSubIndex--;
					print_sub_noBreath();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					noBreathSubIndex--;
					if (noBreathSubIndex < 0) noBreathSubIndex++;
					print_sub_noBreath();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bNoBreath = !bNoBreath;
					print_sub_noBreath();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_noBulletdrop): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					noBulletdropSubIndex++;
					if (noBulletdropSubIndex > 1) noBulletdropSubIndex--;
					print_sub_noBulletdrop();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					noBulletdropSubIndex--;
					if (noBulletdropSubIndex < 0) noBulletdropSubIndex++;
					print_sub_noBulletdrop();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bNoBulletdrop = !bNoBulletdrop;
					print_sub_noBulletdrop();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_RateofFire): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					rofSubindex++;
					if (rofSubindex > 1) rofSubindex--;
					print_sub_RateofFire();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					rofSubindex--;
					if (rofSubindex < 0) rofSubindex++;
					print_sub_RateofFire();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bROF = !bROF;
					print_sub_RateofFire();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}

		case ((size_t)MenuIndex::m_damageHack): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					damageSubIndex++;
					if (damageSubIndex > 1) damageSubIndex--;
					print_sub_Damagehack();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					damageSubIndex--;
					if (damageSubIndex < 0) damageSubIndex++;
					print_sub_Damagehack();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bDamageHack = !bDamageHack;
					print_sub_Damagehack();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}
		case((size_t)MenuIndex::m_instantHit): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					instanthitSubIndex++;
					if (instanthitSubIndex > 1) instanthitSubIndex--;
					print_sub_InstantHit();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					instanthitSubIndex--;
					if (instanthitSubIndex < 0) instanthitSubIndex++;
					print_sub_InstantHit();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bInstantHit = !bInstantHit;
					print_sub_InstantHit();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}
		case((size_t)MenuIndex::m_noVegetation): {

			if (bIsSubIndex == true) {

				if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
					noVegetationSubIndex++;
					if (noVegetationSubIndex > 1) noVegetationSubIndex--;
					print_sub_NoVegetation();
				}

				if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
					noVegetationSubIndex--;
					if (noVegetationSubIndex < 0) noVegetationSubIndex++;
					print_sub_NoVegetation();
				}

				if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
					bNoVegetaion = !bNoVegetaion;
					print_sub_NoVegetation();
				}

				if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
					bIsSubIndex = false;
					update_mainIndexes();
				}
			}
			Sleep(1);
			break;
		}
		}
	}

};



class LocalPlayer {
public:
	float get_Health() {
		return mem->rpm<float>(o->HealthComponent + 0x20);
	}
	WeaponSlot get_ActiveSlot() {
		return mem->rpm<WeaponSlot>(o->ClientSoldierWeaponsComponent + 0xA98);
	}
	bool isAlive() {
		if (((mem->rpm<float>(o->HealthComponent + 0x20)) > 0)) {
			return true;
		}
	}

private:
	Offsets* o = new Offsets;
};




static __forceinline BOOLEAN IsValid(PVOID ptr) {
	return (ptr >= (PVOID)0x10000) && (ptr < PTRMAXVAL) && ptr != nullptr && (ptr, sizeof(ptr));
}

void ReadBase() {
	Offsets* o = new Offsets;
	o->ClientManager;
	if (!IsValid((PVOID)o->ClientManager)) return;

	o->LocalPlayer;
	if (!IsValid((PVOID)o->LocalPlayer)) return;

	o->ClientSoldierEntity;
	if (!IsValid((PVOID)o->ClientSoldierEntity)) return;

	o->ClientSoldierWeaponsComponent;
	if (!IsValid((PVOID)o->ClientSoldierWeaponsComponent)) return;

	o->CurrentAnimatedWeaponHandler;
	if (!IsValid((PVOID)o->CurrentAnimatedWeaponHandler)) return;

	o->ClientSoldierWeapon;
	if (!IsValid((PVOID)o->ClientSoldierWeapon)) return;

	o->ClientSoldierBreathControlComponent;
	if (!IsValid((PVOID)o->ClientSoldierBreathControlComponent)) return;

	o->HealthComponent;
	if (!IsValid((PVOID)o->HealthComponent)) return;

	o->ActiveSlot;
	if (!IsValid((PVOID)o->ActiveSlot)) return;
	Sleep(1);
	delete o;
}

void NoBulletGravity() {
	if (bNoBulletdrop == true) {
		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;

		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 WeaponFiringData = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x128);
			if (!IsValid((PVOID)WeaponFiringData)) return;
			DWORD64 FiringFunctionData = mem->rpm<DWORD64>(WeaponFiringData + 0x10);
			if (!IsValid((PVOID)FiringFunctionData)) return;
			DWORD64 BulletEntityData = mem->rpm<DWORD64>(FiringFunctionData + 0xB0);
			if (!IsValid((PVOID)BulletEntityData)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<float>(BulletEntityData + 0x130, 0.0f);
			}
		}
		Sleep(1);
		delete pPlayer;
		delete o;
	}
}

void NoBreath() {
	if (bNoBreath == true) {
		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 m_Breath = mem->rpm<DWORD64>(o->ClientSoldierBreathControlComponent + 0x48);
			if (!IsValid((PVOID)m_Breath)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<int>(o->ClientSoldierBreathControlComponent + 0x58, 1);
			}
		}
		Sleep(1);
		delete pPlayer;
	}
}




void ROF() {
	if (bROF == true) {
		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 WeaponFiringData = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x128);
			if (!IsValid((PVOID)WeaponFiringData)) return;
			DWORD64 FiringFunctionData = mem->rpm<DWORD64>(WeaponFiringData + 0x10);
			if (!IsValid((PVOID)FiringFunctionData)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<float>(FiringFunctionData + 0x1C8, 1500.0f);
			}
		}
		Sleep(1);
		delete pPlayer;
		delete o;
	}
}

void NoRecoil() {
 		if (bNoRecoil == true) {
			//float ShootingRecoilDeceaseScale{}; 0x0440  sett til 100
			//float FirstShotMultiplayer{}; 0x0444 sett til 0
			Offsets* o = new Offsets;
			LocalPlayer* pPlayer = new LocalPlayer;
			if (pPlayer->isAlive()) {

				DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
				if (!IsValid((PVOID)CurrentWeaponFiring)) return;
				DWORD64 GunSway = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x78);
				if (!IsValid((PVOID)GunSway)) return;
				DWORD64 GunSwayData = mem->rpm<DWORD64>(GunSway + 0x8);
				if (!IsValid((PVOID)GunSwayData)) return;

				if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
					mem->wpm<float>(GunSwayData + 0x440, 100.0f);
					mem->wpm<float>(GunSwayData + 0x444, 0.0f);
				}
			}
			Sleep(1);
			delete pPlayer;
			delete o;
		}
}

void NoSpread() {
	if (bNoSpread == true) {
		//float DeviationScaleFactorZoom{}; //0x0430
		//float GaplayDeviationScaleFactorZoom{}; //0x0434
		//float DeviationScaleFactorNoZoom{}; //0x0438
		//float GaplayDeviationScaleFactorNoZoom{}; //0x043C
		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 GunSway = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x78);
			if (!IsValid((PVOID)GunSway)) return;
			DWORD64 GunSwayData = mem->rpm<DWORD64>(GunSway + 0x8);
			if (!IsValid((PVOID)GunSwayData)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<float>(GunSwayData + 0x430, 0.0f);
				mem->wpm<float>(GunSwayData + 0x434, 0.0f);
				mem->wpm<float>(GunSwayData + 0x438, 0.0f);
				mem->wpm<float>(GunSwayData + 0x43C, 0.0f);
			}
		}
		Sleep(1);
		delete pPlayer;
		delete o;
	}
}

void DamageHack() {
	if (bDamageHack == true) {

		//float StartDamage = mem->rpm<float>(BulletEntityData + 0x154);
		//float EndDamage = mem->rpm<float>(BulletEntityData + 0x158);
		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 WeaponFiringData = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x128);
			if (!IsValid((PVOID)WeaponFiringData)) return;
			DWORD64 FiringFunctionData = mem->rpm<DWORD64>(WeaponFiringData + 0x10);
			if (!IsValid((PVOID)FiringFunctionData)) return;
			DWORD64 BulletEntityData = mem->rpm<DWORD64>(FiringFunctionData + 0xB0);
			if (!IsValid((PVOID)BulletEntityData)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<float>(BulletEntityData + 0x158, 100.0f);
			}
		}
		Sleep(1);
		delete pPlayer;
		delete o;
	}
}




void InstantHit() {

	if (bInstantHit == true) {

		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 WeaponFiringData = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x128); //p1
			if (!IsValid((PVOID)WeaponFiringData)) return;
			DWORD64 FiringFunctionData = mem->rpm<DWORD64>(WeaponFiringData + 0x10); //p2
			if (!IsValid((PVOID)FiringFunctionData)) return;
			DWORD64 BulletEntityData = mem->rpm<DWORD64>(FiringFunctionData + 0xB0); // p3
			if (!IsValid((PVOID)BulletEntityData)) return;

			if (pPlayer->get_ActiveSlot() == WeaponSlot::m_primary || pPlayer->get_ActiveSlot() == WeaponSlot::m_secondary) {
				mem->wpm<byte>(BulletEntityData + 0x16D, 1);
			}
		}
		Sleep(1);
		delete pPlayer;
		delete o;
	}
	else if (bInstantHit == false){

		Offsets* o = new Offsets;
		LocalPlayer* pPlayer = new LocalPlayer;
		if (pPlayer->isAlive()) {

			DWORD64 CurrentWeaponFiring = mem->rpm<DWORD64>(o->ClientSoldierWeapon + 0x49C0);
			if (!IsValid((PVOID)CurrentWeaponFiring)) return;
			DWORD64 WeaponFiringData = mem->rpm<DWORD64>(CurrentWeaponFiring + 0x128); //p1
			if (!IsValid((PVOID)WeaponFiringData)) return;
			DWORD64 FiringFunctionData = mem->rpm<DWORD64>(WeaponFiringData + 0x10); //p2
			if (!IsValid((PVOID)FiringFunctionData)) return;
			DWORD64 BulletEntityData = mem->rpm<DWORD64>(FiringFunctionData + 0xB0); // p3

			if (!IsValid((PVOID)BulletEntityData)) return;
			if (mem->rpm<byte>(BulletEntityData + 0x16D) == 1) {
				mem->wpm<byte>(BulletEntityData + 0x16D, 0);
			}
		}
		delete pPlayer;
		delete o;
	}
	
}


void NoVegetation() { // doesnt work

	if (bNoVegetaion == true) {
		if (mem->rpm<byte>(0x643D2070 + 0x266) == 1)
		mem->wpm<byte>(0x643D2070 + 0x266, 0);
	}
	else {
		if (mem->rpm<byte>(0x643D2070 + 0x266) == 0)
			mem->wpm<byte>(0x643D2070 + 0x266, 1);
	}
}

void ReadEnemy() {
	for (int index = 0; index < 70; index++) {
		
		Offsets* o = new Offsets;
		Dankmem* mem = new Dankmem;
		DWORD64 IdToPlayerMapOffset = mem->rpm<DWORD64>(o->ClientManager + 0x548);
		DWORD64 pPlayer = mem->rpm<DWORD64>(IdToPlayerMapOffset + (index * 0x8));
		//if (!IsValid((PVOID)pPlayer)) return;
		int enemy_TeamID = mem->rpm<int>(pPlayer + 0x13cc);
		char enemy_Name = mem->rpm<char>(pPlayer + 0x40);
		
		DWORD64 pCharacter = mem->rpm<DWORD64>(pPlayer + 0x14b0);
		DWORD64 pSoldier = mem->rpm<DWORD64>((pCharacter) - 0x8);
		DWORD64 SpottingTargetComponentData = mem->rpm<DWORD64>(pSoldier + 0xbf0);
		int SpotType = mem->rpm<int>(SpottingTargetComponentData + 0x50);
		
		if (SpotType == 0) {
			mem->wpm<int>(SpottingTargetComponentData + 0x50, 1);
		}

		
		delete o;
		delete mem;
	}

	
	
	
}

int main() {
	SetConsoleTitle("Skype"); // Stealth 100
	MenuText* menuTxt = new MenuText;
	MenuControl* menuCtl = new MenuControl;
	menuTxt->print_mainIndexes();
	menuTxt->print_procStatus();
	mem->wpm<byte>(0x641a2070 + 0x275, 0);
	while (true) {
		menuCtl->navigate_mainIndexes();
		menuCtl->navigate_subIndexes();
		ReadBase();
		NoRecoil();
		NoSpread();
		NoBreath();
		NoBulletGravity();
		ROF();
		DamageHack();
		InstantHit();
		NoVegetation();
		
	}

	CloseHandle(hConsole);
	delete menuCtl;
	delete menuTxt;
	delete mem;
}