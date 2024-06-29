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
	Vector2 randomPos = getRandomPos(player);
	player->newPos = randomPos;
}
Vector2 Item_A_RandomMove::getRandomPos(Player* p)
{
	auto map = Core::GetInst()->arrMap;
generateRandomPos:
	srand(time(NULL));
	int xRandom = rand() % 30 + 5;
	int yRandom = rand() % 30 + 5;
	Vector2 vecArr[10];
	int vecArrInd = 0;

	for (int i = yRandom - 5; i < yRandom + 5; i++) {
		for (int j = xRandom - 5; j < xRandom + 5; j++) {
			//map[i][j] = (char)OBJ_TYPE::ITEM_TELEPORT;
			if (vecArrInd > 9) {
				Vector2 result = vecArr[rand() % vecArrInd];
				return result;
			}
			if (map[i][j] == (char)OBJ_TYPE::ROAD && i != p->currentPos.x && j != p->currentPos.y) {
				vecArr[vecArrInd++] = Vector2(i, j);
			}
		}
	}
	if (vecArrInd < 1) goto generateRandomPos;
	Vector2 result = vecArr[rand() % vecArrInd];
	return result;
}