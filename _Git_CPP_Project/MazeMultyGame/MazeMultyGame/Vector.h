#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
public:
	int x;
	int y;
	static int GetDistanceSqrt(Vector2 pos1, Vector2 pos2);
//public:
	//static const Vector2 up;
};

