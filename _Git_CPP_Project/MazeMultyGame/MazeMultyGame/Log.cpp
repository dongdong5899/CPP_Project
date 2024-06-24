#include "Log.h"
int Log::currentSize = 0;
Vector2 Log::startPos = Vector2(22, 1);

Vector2 Log::GetPos()
{
	Vector2 pos = startPos;
	pos.y += currentSize++;
	if (maxSize < pos.y) {
		std::system("cls");
		currentSize = 0;
		pos = startPos;
	}
	return pos;
}
