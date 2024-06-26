#include "Item.h"
#include "Console.h"
#include "Log.h"
void Item_A_RandomMove::UseItem(Player isP1)
{
	//random move
	Vector2 pos = Log::GetPos();
	GotoPos(pos.x, pos.y);
	cout << "used_item";
	cout << "_random_Move";//item name
	Vector2 randomPos = getRandomPos();

}
Vector2 Item_A_RandomMove::getRandomPos()
{
	//Vector2 result = 
	return Vector2();
}