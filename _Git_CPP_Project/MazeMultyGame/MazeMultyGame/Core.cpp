#include "Core.h"
#include "MazeMap.h"
#include <string.h>
#include <algorithm>
#include <math.h>
#include "Core.h"
#include "Console.h"
Core* Core::m_pInst = nullptr;
Core::Core() {

}

Vector2 GetMovePos(char _arrMap[MAP_HEIGHT][MAP_WIDTH], Vector2 startPos, bool isArrow = true);

#define RenderLevel 7
const char Wall[RenderLevel][4] = { "  ", "ㆍ", "＊", "ㅁ", "□", "▣", "■"};

bool Core::Init(Player* _player1, Player* _player2)
{
	system("title 22Bombman | mode con cols=80 lines=40");

	CursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);

	CreatMazeMap(arrMap);

	player1 = _player1;
	player2 = _player2;
	return true;
}
void Core::Run()
{
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

	player1->Move(arrMap);
	player2->Move(arrMap);
}

void Core::Render()
{
	GotoPos(0, 0);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			//플레이어들과의 거리
			int player1Dis = player1->isBlind ? 0 : RenderLevel - 1 -
				((int)pow(pow((player1->currentPos.x - j), 2) + pow((player1->currentPos.y - i), 2), 0.7f) - 1);
			if (player1Dis < 0) player1Dis = 0;

			int player2Dis = player2->isBlind ? 0 : RenderLevel - 1 -
				((int)pow(pow((player2->currentPos.x - j), 2) + pow((player2->currentPos.y - i), 2), 0.7f) - 1);
			if (player2Dis < 0) player2Dis = 0;

			int playersDis = player1Dis + player2Dis;
			if (playersDis > RenderLevel - 1) playersDis = RenderLevel - 1;

			//그리기
			if (player1->currentPos.x == j && player1->currentPos.y == i)
				cout << "●";
			else if (player2->currentPos.x == j && player2->currentPos.y == i)
				cout << "○";


			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << Wall[playersDis];
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
