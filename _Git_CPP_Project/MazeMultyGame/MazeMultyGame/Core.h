#pragma once
#include "define.h"
#include "Player.h"
#include<iostream>
#include "Item.h"
class Core
{
private:
	Core();
	//~Core();
public:
	bool Init();
	void Run();
	void Physics();
	void CollisionDetection(Player* player, Vector2 newPos);
	static Core* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Core;
		return m_pInst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_pInst);
	}
	Player* GetAther(Player* player);
	
	void UseItem(OBJ_TYPE type, Player* p);
	void WallBreak(Vector2 pos);
	void AddTime(int time);
private:
	std::map<OBJ_TYPE, Item*> itemDictionary;
	void Update();
	void Render();
	void PlayerInit();
	void End();
	static Core* m_pInst;
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};
	int timer;
	int time_s;
	int time_m;
	bool isEnd = false;
	bool arrowWin = false;

	Player* player1;
	Player* player2;
};