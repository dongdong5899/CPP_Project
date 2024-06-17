#pragma once
#include "Vector.h"
#include "Item_A_RandomMove.h"
#include "MonoBehavior.h"
class Player : public MonoBehavior
{
public:
	Item* item = nullptr;
	Vector2 currentPos;
};

