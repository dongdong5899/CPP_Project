#include "Item.h"
#include "Console.h"
#include "Core.h"
void Item_A_Blind::UseItem(Player* player)
{
	Player* stopPlayer = Core::GetInst()->GetAther(player);
	stopPlayer->Blind(3000);
}