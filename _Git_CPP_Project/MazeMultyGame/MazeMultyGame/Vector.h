#pragma once
namespace VietEngine {
	class Vector2
	{
	public:
		Vector2();
		Vector2(int x, int y);

		int x;
		int y;

		static const Vector2 up;
		static int GetDistanceSqrt(Vector2 pos1, Vector2 pos2);
	};
}

