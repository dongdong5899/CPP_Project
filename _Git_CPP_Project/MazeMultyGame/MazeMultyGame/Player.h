#pragma once
#include "Vector.h"
#include "define.h"

using namespace VietEngine;
class Player
{
public:
	Vector2 currentPos;
	bool isBlind = false;

	Player(bool _isArrowInput);
	void Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH]);
	int GetRenderDistance(int x, int y);
private:
	bool isArrowInput = false;
	int eyesight = 1;
	clock_t lastMoveTime = 0;
	clock_t moveDelay = 100;
};

