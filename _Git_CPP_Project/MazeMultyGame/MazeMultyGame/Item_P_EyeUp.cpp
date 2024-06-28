#include "Item.h"
#include "Console.h"
#include "Core.h"
void Item_P_EyeUp::UseItem(Player* player)
{
	player->EyeUp();
}