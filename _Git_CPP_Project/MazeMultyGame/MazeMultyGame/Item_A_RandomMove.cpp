#include "Item_A_RandomMove.h"
#include "Console.h"
#include "Log.h"
void Item_A_RandomMove::UseItem(bool isP1)
{
	//random move
	Vector2 pos = Log::GetPos();
	GotoPos(pos.x, pos.y);
	cout << "used_item";
	cout << "_random_Move";//item name
	Vector2 randomPos = getRandomPos();
	if (isP1) {
	}
}
Vector2 Item_A_RandomMove::getRandomPos()
{
	//Vector2 result = 
	return Vector2();
}