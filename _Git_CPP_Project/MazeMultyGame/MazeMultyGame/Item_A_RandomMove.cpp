#include "Item_A_RandomMove.h"
#include "Console.h"
#include "Log.h"
void Item_A_RandomMove::UseItem()
{
	
	Vector2 pos = Log::GetPos();
	GotoPos(pos.x, pos.y);
	cout << "ming";
}