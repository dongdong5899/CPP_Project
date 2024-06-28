#include <string.h>
#include <algorithm>
#include "Core.h"
#include "MazeMap.h"
#include "Console.h"
#include "Vector.h"
#include "Title.h"
Core* Core::m_pInst = nullptr;
Core::Core()
{

}
const char Wall[RenderLevel][4] = { "  ", "ㆍ", "＊", "ㅁ", "□", "▣", "■"};
bool Core::Init()
{
	//FullScrean();
	system("title 22Bombman | mode con cols=100 lines=50");

	CursorVis(false, 1);
	LockResize();
	SetFontSize(FW_BOLD, 20, 20);

	CreatMazeMap(arrMap);
	//arrMap[1][0] = (char)OBJ_TYPE::ITEM_TELEPORT;

	if (itemDictionary.empty())
	{
		itemDictionary.emplace(OBJ_TYPE::ITEM_TELEPORT, new Item_A_RandomMove);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_LIGHT, new Item_A_Light);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_STOP, new Item_A_Stop);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_BLIND, new Item_A_Blind);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_WALLBREAK, new Item_A_WallBreak);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_EYEUP, new Item_P_EyeUp);// adds item
		itemDictionary.emplace(OBJ_TYPE::ITEM_TIME, new Item_P_Time);// adds item
	}

	isEnd = false;

	player1 = new Player(false);
	player2 = new Player(true);
	player1->currentPos = Vector2(0, 0);
	player2->currentPos = Vector2(MAP_WIDTH - 1, MAP_HEIGHT - 1);
	return true;
}
void Core::Run()
{
	timer = clock();
	time_s = 0;
	time_m = 2;
	PlayerInit();
	while (true)
	{
		Update();
		if (isEnd) break;
		Physics();
		Render();
		//Sleep(25);
	}
	End();
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

	if (arrMap[newPos.y][newPos.x] == (char)OBJ_TYPE::WALL)
	{
		if (newPos.x == currentPos.x)
			newPos.y = currentPos.y;
		else if (newPos.y == currentPos.y)
			newPos.x = currentPos.x;
		else
		{
			if (arrMap[currentPos.y][newPos.x] != (char)OBJ_TYPE::WALL)
				newPos.y = currentPos.y;
			else if (arrMap[newPos.y][currentPos.x] != (char)OBJ_TYPE::WALL)
				newPos.x = currentPos.x;
			else
				newPos = currentPos;
		}
	}


	player->currentPos = newPos;

	//item detection
	if (arrMap[player->currentPos.y][player->currentPos.x] != (char)OBJ_TYPE::ROAD) {
		player->AddItem((OBJ_TYPE)arrMap[player->currentPos.y][player->currentPos.x]);
		arrMap[player->currentPos.y][player->currentPos.x] = (char)OBJ_TYPE::ROAD;
	}
}
Player* Core::GetAther(Player* player)
{
	if (player == player1)
		return player2;
	else
		return player1;
}
void Core::UseItem(OBJ_TYPE type, Player* p)
{
	itemDictionary[type]->UseItem(p);
}
void Core::WallBreak(Vector2 pos)
{
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			int xPos = pos.x + x;
			int yPos = pos.y + y;

			if (xPos >= MAP_WIDTH || xPos < 0 || 
				yPos >= MAP_HEIGHT || yPos < 0)
				continue;

			if (arrMap[yPos][xPos] == (char)OBJ_TYPE::WALL)
			{
				for (int i = 0; i < 6; i++)
				{
					arrMap[yPos][xPos] = (char)OBJ_TYPE::ROAD;
				}
			}
		}
	}
}
void Core::AddTime(int time)
{
	time_s += time;
	if (time_s < 0)
	{
		time_s += 60;
		--time_m;
		if (time_m < 0)
		{
			isEnd = true;
			arrowWin = false;
			time_s = 0;
			time_m = 0;
		}
	}
	else if (time_s >= 60)
	{
		time_s -= 60;
		++time_m;
	}
}

void Core::Update()
{
	player1->Move(arrMap);
	player2->Move(arrMap);

	if (clock() - timer >= 1000)
	{
		timer = clock();
		AddTime(-1);
	}

	if (player1->currentPos == player2->currentPos)
	{
		isEnd = true;
		arrowWin = true;
	}
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
			{
				SetColor((int)COLOR::YELLOW);
				cout << "●";
				SetColor((int)COLOR::WHITE);
			}
			else if (player2->currentPos.x == j && player2->currentPos.y == i)
			{
				SetColor((int)COLOR::YELLOW);
				cout << "○";
				SetColor((int)COLOR::WHITE);
			}
			else if (arrMap[i][j] == (char)OBJ_TYPE::WALL)
				cout << Wall[playersDis];
			else if (arrMap[i][j] == (char)OBJ_TYPE::ROAD)
				cout << "  ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_LIGHT)
				cout << "光";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_WALLBREAK)
				cout << "※";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_TELEPORT)
				cout << "℡";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_STOP)
				cout << "Θ";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_BLIND)
				cout << "∮";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_TIME)
				cout << "™";
			else if (arrMap[i][j] == (char)OBJ_TYPE::ITEM_EYEUP)
				cout << "↑";
		}
		cout << endl;
	}

	char startChar = (char)OBJ_TYPE::ITEM_LIGHT;
	for (int i = 0; i < 2; i++)
	{
		int xPos = (MAP_WIDTH - 8) * i;
		int yPos = MAP_HEIGHT + 1;
		GotoPos(xPos, yPos);
		cout << "Player" << i + 1;
		Player* p = i == 0 ? player1 : player2;
		GotoPos(xPos, yPos + 1);
		cout << "순간이동 : " << p->itemDictionary[OBJ_TYPE::ITEM_TELEPORT];
		GotoPos(xPos, yPos + 2);
		cout << "근처 벽 부수기 : " << p->itemDictionary[OBJ_TYPE::ITEM_WALLBREAK];
		GotoPos(xPos, yPos + 3);
		cout << "시아 레벨 : " << p->eyesight;
		GotoPos(xPos, yPos + 4);
		cout << (p->isBlind ? "실명" : " ");
		GotoPos(xPos, yPos + 5);
		cout << (p->canMove == false ? "구속" : " ");
	}
	GotoPos(MAP_WIDTH / 2 - 1, MAP_HEIGHT + 1);
	cout << time_m << ":";
	cout.width(2);
	cout.fill('0');
	cout << time_s;
}
void Core::PlayerInit()
{
	player1->Init();
	player2->Init();
}

void Core::End()
{
	system("cls");
	GotoPos(MAP_WIDTH / 2, MAP_HEIGHT / 1.5f);
	cout << (arrowWin ? "술래 승리!" : "도망자 승리!");

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			break;
	}
	Init();
	Title::GetInst()->Start();
}
