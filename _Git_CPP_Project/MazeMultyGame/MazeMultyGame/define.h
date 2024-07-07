#pragma once
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;
const int MAP_WIDTH = 31;
const int MAP_HEIGHT = 30;
#include<Windows.h>
enum class OBJ_TYPE
{
	WALL = '0', ROAD, ITEM_LIGHT, ITEM_WALLBREAK, ITEM_TELEPORT, ITEM_STOP, ITEM_BLIND, ITEM_TIME, ITEM_EYEUP
};
#define SAFE_DELETE(p) if (p != nullptr){ delete p;	p = nullptr;}
#define RenderLevel 7