#include "Item.h"
#include "Console.h"
#include "Core.h"
void Item_A_WallBreak::UseItem(Player* player)
{
	Core::GetInst()->WallBreak(player->currentPos);
}