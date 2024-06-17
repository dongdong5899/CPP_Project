#include "Core.h"
#include <time.h>

Player::Player(bool _isArrowInput)
{
	isArrowInput = _isArrowInput;
}

void Player::Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH])
{
	if (lastMoveTime + moveDelay > clock()) return;
	lastMoveTime = clock();

	Vector2 newPos = currentPos;

	//ют╥б
	if (GetAsyncKeyState(isArrowInput ? VK_UP : 0x57) & 0x8000)
		newPos.y--;
	if (GetAsyncKeyState(isArrowInput ? VK_DOWN : 0x53) & 0x8000)
		newPos.y++;
	if (GetAsyncKeyState(isArrowInput ? VK_LEFT : 0x41) & 0x8000)
		newPos.x--;
	if (GetAsyncKeyState(isArrowInput ? VK_RIGHT : 0x44) & 0x8000)
		newPos.x++;

	//Clamp
	if (newPos.x >= MAP_WIDTH || newPos.x < 0)
		newPos.x = currentPos.x;
	if (newPos.y >= MAP_HEIGHT || newPos.y < 0)
		newPos.y = currentPos.y;


	if (_arrMap[newPos.y][newPos.x] == (char)Core::OBJ_TYPE::WALL)
	{
		if (newPos.x == currentPos.x)
			newPos.y = currentPos.y;
		else if (newPos.y == currentPos.y)
			newPos.x = currentPos.x;
		else
		{
			if (_arrMap[currentPos.y][newPos.x] == (char)Core::OBJ_TYPE::ROAD)
				newPos.y = currentPos.y;
			else if (_arrMap[newPos.y][currentPos.x] == (char)Core::OBJ_TYPE::ROAD)
				newPos.x = currentPos.x;
			else
				newPos = currentPos;
		}
	}

	currentPos = newPos;
}

int Player::GetRenderDistance(int x, int y)
{
	int renderDis = isBlind ? RenderLevel : 1 +
		(int)pow(Vector2::GetDistanceSqrt(currentPos, Vector2(x, y)), 0.7f) - eyesight;
	renderDis = RenderLevel - renderDis;
	if (renderDis < 0) renderDis = 0;
	return renderDis;
}
