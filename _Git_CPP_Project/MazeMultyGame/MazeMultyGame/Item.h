#pragma once
#include "Vector.h"
#include "Player.h"

class Item abstract
{

public:
	virtual void UseItem(Player* player);
};

class Item_A_RandomMove : public Item
{
public:
	virtual void UseItem(Player* player) override;
//private:
//	Vector2 GetRandomPos(Player* p);
};

class Item_A_Light : public Item
{
public:
	virtual void UseItem(Player* player) override;
};
class Item_A_Stop : public Item
{
public:
	virtual void UseItem(Player* player) override;
};
class Item_A_Blind : public Item
{
public:
	virtual void UseItem(Player* player) override;
};
class Item_A_WallBreak : public Item
{
public:
	virtual void UseItem(Player* player) override;
};
class Item_P_EyeUp : public Item
{
public:
	virtual void UseItem(Player* player) override;
};
class Item_P_Time : public Item
{
public:
	virtual void UseItem(Player* player) override;
};