#include "Item.h"
#include "Console.h"
#include "Core.h"
void Item_A_Stop::UseItem(Player* player)
{
	Player* stopPlayer = Core::GetInst()->GetAther(player);
	stopPlayer->Stop(3000);
}