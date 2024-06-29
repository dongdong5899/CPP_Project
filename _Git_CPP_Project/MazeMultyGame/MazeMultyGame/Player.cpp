#include "Core.h"
#include <time.h>
//#include "Player.h"

Player::Player(bool _isArrowInput)
{
	isArrowInput = _isArrowInput;
	
}

void Player::Move(char _arrMap[MAP_HEIGHT][MAP_WIDTH])
{
	if (lastMoveTime + moveDelay > clock()) return;
	lastMoveTime = clock();
	if (isLight && lightStartTime + lightTime < clock())
	{
		isLight = false;
	}
	if (isBlind && blindStartTime + blindTime < clock())
	{
		isBlind = false;
	}
	if (canMove == false)
	{
		if (stopStartTime + stopTime < clock())
		{
			canMove = true;
		}
		else
		{
			return;
		}
	}
	if (!canUseItem && itemStartTime + itemTime < clock()) {
		canUseItem = true;
	}

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
	if ((isArrowInput ? GetKey(VK_RETURN) : GetKey('E')) && canUseItem) {
		itemStartTime = clock();
		itemTime = 800;
		canUseItem = false;
		TryUseItem(OBJ_TYPE::ITEM_TELEPORT);
	}
	if ((isArrowInput ? GetKey(VK_RSHIFT) : GetKey('F')) && canUseItem) {
		itemStartTime = clock();
		itemTime = 800;
		canUseItem = false;
		TryUseItem(OBJ_TYPE::ITEM_WALLBREAK);
	}
}

bool Player::GetKey(int input)
{
	return GetAsyncKeyState(input) & 0x8000;
}


int Player::GetRenderDistance(int x, int y)
{
	if (isLight) return 10;
	int renderDis = isBlind ? RenderLevel : 1 +
		(int)pow(Vector2::GetDistanceSqrt(currentPos, Vector2(x, y)), 0.7f) - eyesight;
	renderDis = RenderLevel - renderDis;
	if (renderDis < 0) renderDis = 0;
	return renderDis;
}

void Player::AddItem(OBJ_TYPE type, int amount)
{
	itemDictionary[type] += amount;
	if (type != OBJ_TYPE::ITEM_TELEPORT &&
		type != OBJ_TYPE::ITEM_WALLBREAK)
	{
		TryUseItem(type);
	}
}

//void Player::SetItem(Item* item)
//{
//	this->item = item;
//}

void Player::Init()
{
	newPos = currentPos;
}

void Player::SetLight(float time)
{
	lightStartTime = clock();
	lightTime = time;
	isLight = true;
}

void Player::Stop(float time)
{
	stopStartTime = clock();
	stopTime = time;
	canMove = false;
}

void Player::Blind(float time)
{
	blindStartTime = clock();
	blindTime = time;
	isBlind = true;
}

void Player::EyeUp()
{
	eyesight += 1;
}

void Player::TryUseItem(OBJ_TYPE ItemType)
{
	if (itemDictionary[ItemType] > 0) {
		Core::GetInst()->UseItem(ItemType, this);
		--itemDictionary[ItemType];
	}
}
