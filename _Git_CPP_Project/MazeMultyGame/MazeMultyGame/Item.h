#pragma once
#include "Vector.h"

class Item abstract
{

public:
	virtual void UseItem(bool isP1) = 0;

};

class Item_A_RandomMove : public Item
{

public:
	virtual void UseItem(bool isP1) override;
private:
	Vector2 getRandomPos();


};