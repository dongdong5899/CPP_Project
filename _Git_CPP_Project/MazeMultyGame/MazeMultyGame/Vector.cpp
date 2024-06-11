#include "Vector.h"
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

}