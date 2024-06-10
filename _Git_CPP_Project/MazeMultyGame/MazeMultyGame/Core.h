﻿#pragma once
#include "define.h"
#include "Player.h"
#include<iostream>
#include<vector>
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
class Core
{
private:
	Core();
	//~Core();
public:
	bool Init(char gayFuck[MAP_HEIGHT][MAP_WIDTH]);
	void Run(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player);
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
		WALL = '0', ROAD, START, GOAL, BOMB, FLASH_BOMB, EXTRA_BOMB, SLIME, PUSH, ITEM
	};
private:
	void Update(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player);
	void Render(char gayFuck[MAP_HEIGHT][MAP_WIDTH], Player& player);
	static Core* m_pInst;
	char arrMap[MAP_WIDTH][MAP_HEIGHT];

};