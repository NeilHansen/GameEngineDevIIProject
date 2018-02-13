#pragma once
#ifndef VECTORS_H_DEF
#define VECTORS_H_DEF
#include <cmath>
#include <iostream>

struct Matrix4
{
	float x;
	float y;
	float z;
	float w;

	Matrix4() : x(0), y(0), z(0), w(0) {};
	Matrix4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

	void        set(float x, float y, float z, float w);
	float       length() const;
	float       distance(const Matrix4& vec) const;     // distance between two vectors
	Matrix4&    normalize();
	float       dot(const Matrix4& vec) const;          // dot product
	bool        equal(const Matrix4& vec, float e) const; // compare with epsilon

														  // operators
	Matrix4     operator-() const;                      // unary operator (negate)
	Matrix4     operator+(const Matrix4& rhs) const;    // add rhs
	Matrix4     operator-(const Matrix4& rhs) const;    // subtract rhs
	Matrix4&    operator+=(const Matrix4& rhs);         // add rhs and update this object
	Matrix4&    operator-=(const Matrix4& rhs);         // subtract rhs and update this object
	Matrix4     operator*(const float scale) const;     // scale
	Matrix4     operator*(const Matrix4& rhs) const;    // multiply each element
	Matrix4&    operator*=(const float scale);          // scale and update this object
	Matrix4&    operator*=(const Matrix4& rhs);         // multiply each element and update this object
	Matrix4     operator/(const float scale) const;     // inverse scale
	Matrix4&    operator/=(const float scale);          // scale and update this object
	bool        operator==(const Matrix4& rhs) const;   // exact compare, no epsilon
	bool        operator!=(const Matrix4& rhs) const;   // exact compare, no epsilon
	bool        operator<(const Matrix4& rhs) const;    // comparison for sort
	float       operator[](int index) const;            // subscript operator v[0], v[1]
	float&      operator[](int index);                  // subscript operator v[0], v[1]

	friend Matrix4 operator*(const float a, const Matrix4 vec);
	friend std::ostream& operator<<(std::ostream& os, const Matrix4& vec);
};

inline float invSqrt(float x)
{
	float xhalf = 0.5f * x;
	int i = *(int*)&x;          // get bits for floating value
	i = 0x5f3759df - (i >> 1);    // gives initial guess
	x = *(float*)&i;            // convert bits back to float
	x = x * (1.5f - xhalf*x*x); // Newton step
	return x;
}

inline Matrix4 Matrix4::operator-() const {
	return Matrix4(-x, -y, -z, -w);
}

inline Matrix4 Matrix4::operator+(const Matrix4& rhs) const {
	return Matrix4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

inline Matrix4 Matrix4::operator-(const Matrix4& rhs) const {
	return Matrix4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

inline Matrix4& Matrix4::operator+=(const Matrix4& rhs) {
	x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this;
}

inline Matrix4& Matrix4::operator-=(const Matrix4& rhs) {
	x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this;
}

inline Matrix4 Matrix4::operator*(const float a) const {
	return Matrix4(x*a, y*a, z*a, w*a);
}

inline Matrix4 Matrix4::operator*(const Matrix4& rhs) const {
	return Matrix4(x*rhs.x, y*rhs.y, z*rhs.z, w*rhs.w);
}

inline Matrix4& Matrix4::operator*=(const float a) {
	x *= a; y *= a; z *= a; w *= a; return *this;
}

inline Matrix4& Matrix4::operator*=(const Matrix4& rhs) {
	x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; return *this;
}

inline Matrix4 Matrix4::operator/(const float a) const {
	return Matrix4(x / a, y / a, z / a, w / a);
}

inline Matrix4& Matrix4::operator/=(const float a) {
	x /= a; y /= a; z /= a; w /= a; return *this;
}

inline bool Matrix4::operator==(const Matrix4& rhs) const {
	return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
}

inline bool Matrix4::operator!=(const Matrix4& rhs) const {
	return (x != rhs.x) || (y != rhs.y) || (z != rhs.z) || (w != rhs.w);
}

inline bool Matrix4::operator<(const Matrix4& rhs) const {
	if (x < rhs.x) return true;
	if (x > rhs.x) return false;
	if (y < rhs.y) return true;
	if (y > rhs.y) return false;
	if (z < rhs.z) return true;
	if (z > rhs.z) return false;
	if (w < rhs.w) return true;
	if (w > rhs.w) return false;
	return false;
}

inline float Matrix4::operator[](int index) const {
	return (&x)[index];
}

inline float& Matrix4::operator[](int index) {
	return (&x)[index];
}

inline void Matrix4::set(float x, float y, float z, float w) {
	this->x = x; this->y = y; this->z = z; this->w = w;
}

inline float Matrix4::length() const {
	return sqrtf(x*x + y*y + z*z + w*w);
}

inline float Matrix4::distance(const Matrix4& vec) const {
	return sqrtf((vec.x - x)*(vec.x - x) + (vec.y - y)*(vec.y - y) + (vec.z - z)*(vec.z - z) + (vec.w - w)*(vec.w - w));
}

inline Matrix4& Matrix4::normalize() {
	//NOTE: leave w-component untouched
	//@@const float EPSILON = 0.000001f;
	float xxyyzz = x*x + y*y + z*z;
	//@@if(xxyyzz < EPSILON)
	//@@    return *this; // do nothing if it is zero vector

	//float invLength = invSqrt(xxyyzz);
	float invLength = 1.0f / sqrtf(xxyyzz);
	x *= invLength;
	y *= invLength;
	z *= invLength;
	return *this;
}

inline float Matrix4::dot(const Matrix4& rhs) const {
	return (x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w);
}

inline bool Matrix4::equal(const Matrix4& rhs, float epsilon) const {
	return fabs(x - rhs.x) < epsilon && fabs(y - rhs.y) < epsilon &&
		fabs(z - rhs.z) < epsilon && fabs(w - rhs.w) < epsilon;
}

inline Matrix4 operator*(const float a, const Matrix4 vec) {
	return Matrix4(a*vec.x, a*vec.y, a*vec.z, a*vec.w);
}

inline std::ostream& operator<<(std::ostream& os, const Matrix4& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	return os;
}