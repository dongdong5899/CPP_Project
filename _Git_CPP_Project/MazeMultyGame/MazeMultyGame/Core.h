#pragma once
#include "define.h"
#include "Player.h"
#include<iostream>
class Core
{
private:
	Core();
	//~Core();
public:
	bool Init(Player* player, Player* player2);
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
	enum class OBJ_TYPE
	{
		WALL = '0', ROAD, START, ITEM_LIGHT, ITEM_WALLBREAK, ITEM_TELEPORT, ITEM_STOP, ITEM_TIME, ITEM_BLIND
	};
private:
	void Update();
	void Render();
	void PlayerInit();
	static Core* m_pInst;

	//gay
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};
	Player* player1;
	Player* player2;
};