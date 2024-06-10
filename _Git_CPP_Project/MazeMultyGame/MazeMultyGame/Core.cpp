#include <string.h>
#include "Core.h"
Core* Core::m_pInst = nullptr;
Core::Core(){

}
bool Core::Init(char gayFuck[MAP_HEIGHT][MAP_WIDTH])
{
	strcpy_s(gayFuck[0], "21111100000000000000");
	strcpy_s(gayFuck[1], "00000111111110000000");
	strcpy_s(gayFuck[2], "00111100000000000000");
	strcpy_s(gayFuck[3], "00000100000000000000");
	strcpy_s(gayFuck[4], "00000111111111100000");
	strcpy_s(gayFuck[5], "00000100000000100000");
	strcpy_s(gayFuck[6], "00000100000000100000");
	strcpy_s(gayFuck[7], "00000100000000100000");
	strcpy_s(gayFuck[8], "00000100000000100000");
	strcpy_s(gayFuck[9], "00000100000000100000");
	strcpy_s(gayFuck[10], "00000100000000111100");
	strcpy_s(gayFuck[11], "00000100000000000000");
	strcpy_s(gayFuck[12], "00000111111111111100");
	strcpy_s(gayFuck[13], "00000100000000001103");
	strcpy_s(gayFuck[14], "00000100000000001001");
	strcpy_s(gayFuck[15], "00000100000000001111");
	strcpy_s(gayFuck[16], "00000100000000000000");
	strcpy_s(gayFuck[17], "00000100000000000100");
	strcpy_s(gayFuck[18], "00000111111111111100");
	strcpy_s(gayFuck[19], "00000000000000000000");
	return false;
}
void Core::Run(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player)
{
	while (true)
	{
		Update(gayFuck, player);
		//system("cls");
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		//커서 관련 구조체
		COORD Cur = { 0, 0 }; //{x * 2, y} 가 더 자연스러울 수도 있음
		//커서 포지션 세팅 함수
		SetConsoleCursorPosition(hOut, Cur);
		Render(gayFuck, player);
		Sleep(25);
	}
}
void Core::Update(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		player.y--;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		player.y++;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		player.x--;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		player.x++;
}

void Core::Render(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player.x== j && player.y == i)
				cout << "P ";
			else if (gayFuck[i][j] == (char)OBJ_TYPE::WALL)
				cout << "■";
			else if (gayFuck[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (gayFuck[i][j] == (char)OBJ_TYPE::START)
				cout << "★";
			else if (gayFuck[i][j] == (char)OBJ_TYPE::GOAL)
				cout << "♨";
			
		}
		cout << endl;
	}
}
