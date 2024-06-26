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
	Player* GetAther(Player player);
	
private:
	void Update();
	void Render();
	void PlayerInit();
	static Core* m_pInst;
	char arrMap[MAP_HEIGHT][MAP_WIDTH]{};

	Player* player1;
	Player* player2;
};