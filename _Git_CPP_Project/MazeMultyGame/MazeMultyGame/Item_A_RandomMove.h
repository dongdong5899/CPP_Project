#pragma once
#include "Item.h"
#include "Vector.h"
class Item_A_RandomMove : public Item
{

public:
	virtual void UseItem(bool isP1) override;
private:
	Vector2 getRandomPos();


};