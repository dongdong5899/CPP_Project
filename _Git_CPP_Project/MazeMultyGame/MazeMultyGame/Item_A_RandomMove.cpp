#include "Item.h"
#include "Console.h"
#include "Log.h"
void Item_A_RandomMove::UseItem(Player* player)
{
	//random move
	Vector2 pos = Log::GetPos();
	GotoPos(pos.x, pos.y);
	cout << "used_item";
	cout << "_random_Move";//item name
	Vector2 randomPos = getRandomPos();
	player->newPos = randomPos;
}
Vector2 Item_A_RandomMove::getRandomPos()
{
	Vector2 result = Vector2(0, 1);
	return result;
}