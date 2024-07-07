#include "Item.h"
#include "Console.h"
#include "Log.h"
#include "Core.h"
#include <time.h>

void Item_A_RandomMove::UseItem(Player* player)
{
	auto map = Core::GetInst()->arrMap;
	Vector2 movablePos[25]{ Vector2() };
	int count = 0;
	for (int i = -2; i < 3; ++i)
	{
		for (int j = -2; j < 3; ++j)
		{
			if (i == 0 && j == 0) continue;
			int posX = player->currentPos.x + i;
			int posY = player->currentPos.y + j;
			if (map[posY][posX] == (char)OBJ_TYPE::ROAD)
			{
				movablePos[count] = Vector2(posX, posY);
				++count;
			}
		}
	}
	Vector2 randomPos = movablePos[rand() % count];

	player->newPos = randomPos;
}
//Vector2 Item_A_RandomMove::GetRandomPos(Player* _player)
//{
//
//generateRandomPos:
//	srand(time(NULL));
//	int xRandom = rand() % 30 + 5;
//	int yRandom = rand() % 30 + 5;
//	Vector2 vecArr[10];
//	int vecArrInd = 0;
//
//
//	for (int i = yRandom - 5; i < yRandom + 5; i++) {
//		for (int j = xRandom - 5; j < xRandom + 5; j++) {
//			//map[i][j] = (char)OBJ_TYPE::ITEM_TELEPORT;
//			if (vecArrInd > 9) {
//				Vector2 result = vecArr[rand() % vecArrInd];
//				return result;
//			}
//			if (map[i][j] == (char)OBJ_TYPE::ROAD && i != _player->currentPos.x && j != _player->currentPos.y) {
//				vecArr[vecArrInd++] = Vector2(i, j);
//			}
//		}
//	}
//	if (vecArrInd < 1) goto generateRandomPos;
//	Vector2 result = vecArr[rand() % vecArrInd];
//	return result;
//}