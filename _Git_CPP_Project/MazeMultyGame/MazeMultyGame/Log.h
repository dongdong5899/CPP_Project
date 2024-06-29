#pragma once
#include"Vector.h"
#include"Console.h"

class Log
{
private:
	Log();
public:
	static Vector2 GetPos();
private:
	static Vector2 startPos;
	static int currentSize;
	static const int maxSize = 40;
};

