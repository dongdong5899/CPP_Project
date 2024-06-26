#pragma once
#include "Vector.h"
#include "define.h"
#include "Item.h"

#include <map>
class Player
{
public:
	std::map<OBJ_TYPE, int> itemDictionary;
	Vector2 currentPos;
	Vector2 newPos;

	bool isBlind = false;

	Player(bool _isArrowInput);
	void Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH]);
	bool GetKey(int input);
	int GetRenderDistance(int x, int y);
	//void SetItem(Item* item);
	void Init();
private:
	
	bool isArrowInput = false;
	int eyesight = 1;
	clock_t lastMoveTime = 0;
	clock_t moveDelay = 100;
};

