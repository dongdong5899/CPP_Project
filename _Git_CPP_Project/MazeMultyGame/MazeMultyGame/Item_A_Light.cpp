#include "Item.h"
void Item_A_Light::UseItem(Player player)
{
	player.SetLight(3000);
}