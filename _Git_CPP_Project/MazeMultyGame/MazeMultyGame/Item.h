#pragma once
#include "Vector.h"
#include "Player.h"

class Item abstract
{

public:
	virtual void UseItem(Player player) = 0;

};

class Item_A_RandomMove : public Item
{

public:
	virtual void UseItem(Player player) override;
private:
	Vector2 getRandomPos();


};

class Item_A_Light : public Item
{
public:
	virtual void UseItem(Player player) override;
};
class Item_A_Stop : public Item
{
public:
	virtual void UseItem(Player player) override;
};