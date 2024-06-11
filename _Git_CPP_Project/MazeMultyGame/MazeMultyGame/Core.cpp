#include <string.h>
#include <algorithm>
#include "Core.h"
#include "Console.h"
Core* Core::m_pInst = nullptr;
Core::Core(){

}
bool Core::Init(Player* _player, Player* _player2)
{
	system("title 22Bombman | mode con cols=80 lines=40");
	
	CursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);

	strcpy_s(arrMap[0],  "11111100000000000000");
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
	player = _player;
	player2 = _player2;
	return true;
}
void Core::Run()
{
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
	Vector2 newPos = player->vector;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		newPos.y--;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		newPos.y++;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		newPos.x--;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		newPos.x++;

	//clamp
	newPos.x = newPos.x < MAP_WIDTH - 2 ? newPos.x : MAP_WIDTH - 2;
	newPos.y = newPos.y < MAP_WIDTH - 1 ? newPos.y : MAP_HEIGHT - 1;

	newPos.x = newPos.x > 0 ? newPos.x : 0;
	newPos.y = newPos.y > 0 ? newPos.y : 0;
	player->vector = newPos;

	Vector2 newPos2 = player2->vector;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		newPos2.y--;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		newPos2.y++;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		newPos2.x--;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		newPos2.x++;

	//clamp
	newPos2.x = newPos2.x < MAP_WIDTH - 2 ? newPos2.x : MAP_WIDTH - 2;
	newPos2.y = newPos2.y < MAP_WIDTH - 1 ? newPos2.y : MAP_HEIGHT - 1;

	newPos2.x = newPos2.x > 0 ? newPos2.x : 0;
	newPos2.y = newPos2.y > 0 ? newPos2.y : 0;
	player2->vector = newPos2;
}

void Core::Render()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "ㅁ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "ㅋ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::GOAL)
				cout << "ㅊ";
		}
		cout << endl;
	}
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { player->vector.x * 2, player->vector.y };
	SetConsoleCursorPosition(hOut, Cur);
	cout << "노";

	//HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
	//cout << "무";
}
