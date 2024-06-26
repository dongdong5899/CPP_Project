
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
	this->newPos = newPos;

	//use item
	if ((isArrowInput ? GetKey('L') : GetKey('E'))) {
		TryUseItem(OBJ_TYPE::ITEM_TELEPORT);
	}
}

bool Player::GetKey(int input)
{
	return GetAsyncKeyState(input) & 0x8000;
}

int Player::GetRenderDistance(int x, int y)
{
	int renderDis = isBlind ? RenderLevel : 1 +
		(int)pow(Vector2::GetDistanceSqrt(currentPos, Vector2(x, y)), 0.7f) - eyesight;
	renderDis = RenderLevel - renderDis;
	if (renderDis < 0) renderDis = 0;
	return renderDis;
}

void Player::AddItem(OBJ_TYPE type, int amount = 1)
{
	itemDictionary[type] += amount;
}

//void Player::SetItem(Item* item)
//{
//	this->item = item;
//}

void Player::Init()
{
	newPos = currentPos;
}

void Player::TryUseItem(OBJ_TYPE ItemType)
{
	if (itemDictionary[ItemType] > 0) {
		itemDictionary[ItemType]--;
		
	}
}
