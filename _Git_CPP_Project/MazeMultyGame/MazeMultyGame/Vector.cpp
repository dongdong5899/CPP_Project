#include "Vector.h"
#include <math.h>
namespace VietEngine {
	const Vector2 Vector2::up = Vector2(0, 1);
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2::Vector2(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	int Vector2::GetDistanceSqrt(Vector2 pos1, Vector2 pos2)
	{
		int distance = pow((pos1.x - pos2.x), 2) + pow((pos1.y - pos2.y), 2);
		return distance;
	}
}