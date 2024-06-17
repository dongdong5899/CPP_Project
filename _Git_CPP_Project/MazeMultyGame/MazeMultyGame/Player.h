#pragma once
#include "Vector.h"
#include "Item_A_RandomMove.h"
#include "MonoBehavior.h"
#include "define.h"
class Player : public MonoBehavior
{
public:
	Item* item = nullptr;
	Vector2 currentPos;
	bool isBlind = false;

	Player(bool _isArrowInput);
	void Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH]);
private:
	bool isArrowInput = false;
	clock_t lastMoveTime = 0;
	clock_t moveDelay = 100;
};

