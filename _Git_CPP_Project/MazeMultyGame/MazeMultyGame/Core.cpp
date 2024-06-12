#include "Core.h"
#include "MazeMap.h"
#include <string.h>
#include <algorithm>
#include "Core.h"
#include "Console.h"
	Core * Core::m_pInst = nullptr;
Core::Core() {

}

Vector2 GetMovePos(Vector2 startPos, bool isArrow = true);

bool Core::Init(Player* _player1, Player* _player2)
{
	system("title 22Bombman | mode con cols=80 lines=40");

	CursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);

	strcpy_s(arrMap[0], "11111100000000000000");
	strcpy_s(arrMap[1], "00000111111110000000");
	strcpy_s(arrMap[2], "00111100000000000000");
	strcpy_s(arrMap[3], "00000100000000000000");
	strcpy_s(arrMap[4], "00000111111111100000");
	strcpy_s(arrMap[5], "00000100000000100000");
	strcpy_s(arrMap[6], "00000100000000100000");
	strcpy_s(arrMap[7], "00000100000000100000");
	strcpy_s(arrMap[8], "00000100000000100000");
	strcpy_s(arrMap[9], "00000100000000100000");
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
	player1 = _player1;
	player2 = _player2;
	return true;
}
void Core::Run()
{
	CreatMazeMap(arrMap);
	while (true)
	{
		Update();
		//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		//COORD Cur = { 0, 0 }; //{x * 2, y} 가 더 자연스러울 수도 있음
		//SetConsoleCursorPosition(hOut, Cur);
		Render();
		Sleep(25);
	}
}
void Core::Update()
{
	//Vector2 newPos = player1->currentPos;
	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//	newPos.y--;
	//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//	newPos.y++;
	//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	//	newPos.x--;
	//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	//	newPos.x++;

	////clamp
	//newPos.x = newPos.x < MAP_WIDTH - 2 ? newPos.x : MAP_WIDTH - 2;
	//newPos.y = newPos.y < MAP_WIDTH - 1 ? newPos.y : MAP_HEIGHT - 1;

	//newPos.x = newPos.x > 0 ? newPos.x : 0;
	//newPos.y = newPos.y > 0 ? newPos.y : 0;
	//player1->currentPos = newPos;

	player1->currentPos = GetMovePos(player1->currentPos, false);
	player2->currentPos = GetMovePos(player2->currentPos, true);
}

Vector2 GetMovePos(Vector2 startPos, bool isArrow)
{
	Vector2 newPos = startPos;

	//입력
	if (GetAsyncKeyState(isArrow ? VK_UP : 0x57) & 0x8000)
		newPos.y--;
	if (GetAsyncKeyState(isArrow ? VK_DOWN : 0x53) & 0x8000)
		newPos.y++;
	if (GetAsyncKeyState(isArrow ? VK_LEFT : 0x41) & 0x8000)
		newPos.x--;
	if (GetAsyncKeyState(isArrow ? VK_RIGHT : 0x44) & 0x8000)
		newPos.x++;

	//Clamp
	if (newPos.x >= MAP_WIDTH - 2 || newPos.x < 0)
		newPos.x = startPos.x;
	if (newPos.y >= MAP_WIDTH - 2 || newPos.y < 0)
		newPos.y = startPos.x;

	//clamp
	/*newPos.x = newPos.x < MAP_WIDTH - 2 ? newPos.x : MAP_WIDTH - 2;
	newPos.y = newPos.y < MAP_WIDTH - 1 ? newPos.y : MAP_HEIGHT - 1;

	newPos.x = newPos.x > 0 ? newPos.x : 0;
	newPos.y = newPos.y > 0 ? newPos.y : 0;*/
	return newPos;
}

void Core::Render()
{
	Gotoxy(0, 0);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (player1->currentPos.x == j && player1->currentPos.y == i)
				cout << "●";
			else if (player2->currentPos.x == j && player1->currentPos.y == i)
				cout << "○";
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << "■";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::START)
				cout << "ㅋ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::GOAL)
				cout << "ㅊ";
		}
		cout << endl;
	}
	/*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { player->vector.x * 2, player->vector.y };
	SetConsoleCursorPosition(hOut, Cur);*/
}
