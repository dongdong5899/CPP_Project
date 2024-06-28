#include "Item.h"
#include "Console.h"
#include "Log.h"
#include "Core.h"
#include <time.h>
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
	auto map = Core::GetInst()->arrMap;
generateRandomPos:
	srand(time(NULL));
	int xRandom = rand() % MAP_WIDTH;
	int yRandom = rand() % MAP_HEIGHT;
	Vector2 result = Vector2(xRandom, yRandom);
	if (map[result.x][result.y] != (char)OBJ_TYPE::ROAD) {
		goto generateRandomPos;
	}

	return result;
}