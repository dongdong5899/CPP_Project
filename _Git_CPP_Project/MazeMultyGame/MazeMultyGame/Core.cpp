#include "Core.h"
#include "MazeMap.h"
#include <string.h>
#include <algorithm>
#include "Core.h"
#include "Console.h"
#include "Vector.h"
Core* Core::m_pInst = nullptr;
Core::Core() {

}

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
		Render();
		Sleep(25);
	}
}
void Core::Update()
{
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
			int player1Dis = player1->GetRenderDistance(j, i);
			int player2Dis = player2->GetRenderDistance(j, i);

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
}
