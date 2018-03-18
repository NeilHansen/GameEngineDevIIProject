#pragma once

struct Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float X, float Y) : x(X), y(Y) {}

	float x, y;

	static Vector2 Distance(Vector2 posA, Vector2 posB)
	{
		return Vector2(posB.x - posA.x, posB.y - posA.y);
	}
};