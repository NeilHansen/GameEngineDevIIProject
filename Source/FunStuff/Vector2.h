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

	static float Dot(Vector2 v1, Vector2 v2) // must be normalized
	{
		return ((v1.x * v2.x) + (v2.y * v2.y));
	}

	// Vector2 Arithmetic
	Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
	Vector2 operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
	Vector2 operator+=(const Vector2& v) const 
	{
		float X = x + v.x, Y = y + v.y;
		return Vector2(X, Y); 
	}
	Vector2 operator-=(const Vector2& v) const
	{
		float X = x - v.x, Y = y - v.y;
		return Vector2(X, Y);
	}

	Vector2 operator*(const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
	Vector2 operator/(const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
	Vector2 operator*=(const Vector2& v) const
	{
		float X = x, Y = y;
		return Vector2(X *= v.x, Y *= v.y);
	}
	Vector2 operator/=(const Vector2& v) const
	{
		float X = x, Y = y;
		return Vector2(X /= v.x, Y /= v.y);
	}

	// Vector2 Binary
	bool operator==(const Vector2& v) const	{ return (x == v.x && y == v.y); }
	bool operator!=(const Vector2& v) const { return !operator==(v); }

	// Vector2/float Arithmetic
	Vector2 operator*(const float& f) const { return Vector2(x * f, y * f); }
	Vector2 operator/(const float& f) const { return Vector2(x * f, y * f); }
};