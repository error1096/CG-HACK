#include<windows.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include "Hprocess.h"



DWORD PlyBase; // we will save player base id in hera
DWORD LocalPlayerBase = 0xA9BDDC; // local ply base
CHackProcess fProcess; // Clinet.dll func


class Game
{

public:

	DWORD CrosshairId = 0xB2A4; // Cross hair Id
	DWORD ForceJump = 0x4F0FE0C; // ForceJump Addr
	DWORD ForceAtt = 0x2EBAF64; //ForceAtt Addr

	int modeOn = 5;
	int modeOff = 4;
	int id;
	int WriteProce(int tmp, DWORD PlayerBase,DWORD offset)
	{
		HWND window = FindWindowA(0, "Counter-Strike: Global Offensive");


		switch (tmp)
		{

		case 1:
		{

			DWORD proid;

			if (window)
			{
				WriteProcessMemory(fProcess.__HandleProcess,
					(PBYTE*)(fProcess.__dwordClient + offset), &modeOn, sizeof(int), 0);

				WriteProcessMemory(fProcess.__HandleProcess,
					(PBYTE*)(fProcess.__dwordClient + offset), &modeOff, sizeof(int), 0);


				return 0;
			}


		}
		break;

		case 2:
		{
			DWORD proid;

			if (window)
			{
				ReadProcessMemory(fProcess.__HandleProcess,
					(PBYTE*)(PlayerBase + offset), &id, sizeof(int), 0);

				return id ; 
			}

			
		}
		}
	}

	void intro()
	{
		SetConsoleTitle("CG-Hack");
		system("color A ");
		system("MODE 40,20");

		std::cout << "---------------------------------------" << std::endl;
		std::cout << "-              CG-HACK-BATE           -" << std::endl;
		std::cout << "-         by ERR0R1096{h3x-g0d}       -" << std::endl;
		std::cout << "-          TAB KEY === STOP           -" << std::endl;
		std::cout << "-          SPACE KEY == AUTOJUMP      -" << std::endl;
		std::cout << "-                  XD                 -" << std::endl;
		std::cout << "-                enjoy                -" << std::endl;
		std::cout << "-      -->      c-137.org     <--     -" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

	}


};

Game game; // Main Process

int main()
{ 
	game.intro();
	fProcess.RunProcess(); // runProcess for client.dll
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)
		(fProcess.__dwordClient + LocalPlayerBase),&PlyBase, sizeof(DWORD), 0);//geting Player Addres

	#define ExitKey VK_TAB
    #define JumpKey VK_SPACE

		while (!GetAsyncKeyState(ExitKey))
		{

			if (game.WriteProce(2, PlyBase, game.CrosshairId) != 0)
				game.WriteProce(1, PlyBase, game.ForceAtt);

			else if (GetAsyncKeyState(JumpKey))
				game.WriteProce(1, PlyBase, game.ForceJump);

		}

	
	system("pause");


}