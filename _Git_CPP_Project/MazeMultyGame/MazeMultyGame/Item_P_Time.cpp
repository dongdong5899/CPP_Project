#include "Item.h"
#include "Console.h"
#include "Core.h"
void Item_P_Time::UseItem(Player* player)
{
	if (player->isArrowInput)
	{
		Core::GetInst()->AddTime(10);
	}
	else
	{
		Core::GetInst()->AddTime(-10);
	}
}