#include "Core.h"
#include "MazeMap.h"
#include <string.h>
Core* Core::m_pInst = nullptr;
Core::Core(){

}
bool Core::Init(Player* _player)
{
	strcpy_s(arrMap[0],  "21111100000000000000");
	strcpy_s(arrMap[1],  "00000111111110000000");
	strcpy_s(arrMap[2],  "00111100000000000000");
	strcpy_s(arrMap[3],  "00000100000000000000");
	strcpy_s(arrMap[4],  "00000111111111100000");
	strcpy_s(arrMap[5],  "00000100000000100000");
	strcpy_s(arrMap[6],  "00000100000000100000");
	strcpy_s(arrMap[7],  "00000100000000100000");
	strcpy_s(arrMap[8],  "00000100000000100000");
	strcpy_s(arrMap[9],  "00000100000000100000");
	strcpy_s(arrMap[10], "00000100000000111100");
	strcpy_s(arrMap[11], "00000100000000000000");
	strcpy_s(arrMap[12], "00000111111111111100");
	strcpy_s(arrMap[13], "00000100000000001103");
	strcpy_s(arrMap[14], "00000100000000001001");
	strcpy_s(arrMap[15], "00000100000000001111");
	strcpy_s(arrMap[16], "00000100000000000000");
	strcpy_s(arrMap[17], "00000100000000000100");
	strcpy_s(arrMap[18], "00000111111111111100");
	strcpy_s(arrMap[19], "00000000000000000000");
	//arrMap = arrMap;
	player = _player;
	return true;
}
void Core::Run()
{
	CreatMazeMap(arrMap);
	while (true)
	{
		Update();
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Cur = { 0, 0 }; //{x * 2, y} 가 더 자연스러울 수도 있음
		SetConsoleCursorPosition(hOut, Cur);
		Render();
		Sleep(25);
	}
}
void Core::Update()
{

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		player->vector->y--;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		player->vector->y++;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		player->vector->x--;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		player->vector->x++;
}

void Core::Render()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if(player->vector->x == j && player->vector->y == i)
				cout << "P ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "■";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "★";
			else if (arrMap[i][j] == (char)OBJ_TYPE::GOAL)
				cout << "♨";
			
		}
		cout << endl;
	}
}
