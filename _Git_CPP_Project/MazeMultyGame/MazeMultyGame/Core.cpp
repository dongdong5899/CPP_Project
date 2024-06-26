#include "Core.h"
#include "MazeMap.h"
#include <string.h>
#include <algorithm>
#include "Console.h"
#include "Vector.h"
Core* Core::m_pInst = nullptr;
Core::Core() {

}

const char Wall[RenderLevel][4] = { "  ", "ㆍ", "＊", "ㅁ", "□", "▣", "■"};

bool Core::Init(Player* _player1, Player* _player2)
{
	//FullScrean();
	system("title 22Bombman | mode con cols=100 lines=50");

	CursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);

	CreatMazeMap(arrMap);
	arrMap[10][10] = (char)Core::OBJ_TYPE::ITEM_TELEPORT;

	player1 = _player1;
	player2 = _player2;
	return true;
}
void Core::Run()
{
	PlayerInit();
	while (true)
	{
		Update();
		Physics();
		Render();
		Sleep(25);
	}
}
void Core::Physics()
{
	CollisionDetection(player1, player1->newPos);
	CollisionDetection(player2, player2->newPos);
}
void Core::CollisionDetection(Player* player, Vector2 newPos)
{
	Vector2 currentPos = player->currentPos;
	if (newPos.x >= MAP_WIDTH || newPos.x < 0)
		newPos.x = currentPos.x;
	if (newPos.y >= MAP_HEIGHT || newPos.y < 0)
		newPos.y = currentPos.y;


	if (arrMap[newPos.y][newPos.x] == (char)Core::OBJ_TYPE::WALL)
	{
		if (newPos.x == currentPos.x)
			newPos.y = currentPos.y;
		else if (newPos.y == currentPos.y)
			newPos.x = currentPos.x;
		else
		{
			if (arrMap[currentPos.y][newPos.x] == (char)Core::OBJ_TYPE::ROAD)
				newPos.y = currentPos.y;
			else if (arrMap[newPos.y][currentPos.x] == (char)Core::OBJ_TYPE::ROAD)
				newPos.x = currentPos.x;
			else
				newPos = currentPos;
		}
	}
	player->currentPos = newPos;

	//item detection
	bool gotItem = false;
	if (arrMap[player->currentPos.y][player->currentPos.x] == (char)Core::OBJ_TYPE::ITEM_TELEPORT) {
		player->SetItem(new Item_A_RandomMove());
		gotItem = true;
	}
	if (gotItem) arrMap[player->currentPos.y][player->currentPos.x] = (char)Core::OBJ_TYPE::ROAD;
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
			//items here
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_TELEPORT) {
				cout << "TT";
			}
		}
		cout << endl;
	}
}
void Core::PlayerInit()
{
	player1->Init();
	player2->Init();
}