#ifndef VEC3_H_
#define VEC3_H_

#include "GameLogger.h"
#include <ostream>

// This is an immutable Vector 2D class
class Vec3
{
public:
	float xx, yy, zz;

public:
	Vec3() : xx(0), yy(0), zz(1) {}
	Vec3(float xx, float yy, float zz) : xx(xx), yy(yy), zz(zz) {}
	Vec3 operator+ (const Vec3& right) const
	{
		return Vec3{ xx + right.xx, yy + right.yy, zz + right.zz };
	}
	Vec3 operator- (const Vec3& right) const
	{
		return Vec3{ xx - right.xx, yy - right.yy, zz - right.zz };
	}
	Vec3 operator- () const
	{
		return Vec3{ -xx, -yy, -zz };
	}
	Vec3 operator* (const Vec3& right) const
	{
		return Vec3{ xx * right.xx, yy * right.yy, zz * right.zz };
	}
	Vec3 operator* (const float right) const
	{
		return Vec3{ xx * right, yy * right, zz * right };
	}
	Vec3 operator/ (const float right) const
	{
		if (right == 0)
		{
			GameLogger::Log(LogMsgType::Error, "Error: Divide by zero.");
		}
		return Vec3{ xx / right, yy / right , zz / right };
	}
	Vec3 Lerp(const Vec3 start, const Vec3 end, const float point) const
	{
		return Vec3{ start + (end - start)*point };
	}
	float Length() const
	{
		return sqrt(LengthSquared());
	}
	float LengthSquared() const
	{
		return xx * xx + yy * yy + zz * zz;
	}
	Vec3 Normalize() const
	{
		float len = Length();
		if (len == 0)
		{
			return Vec3(0, 0, 0);
		}
		else
		{
			return Vec3{ xx / len, yy / len, zz / len };
		}
	}
	Vec3 PerpCW() const
	{
		return Vec3{ yy, -xx, 0};
	}
	Vec3 PerpCCW() const
	{
		return Vec3{ -yy, xx, 0};
	}
	float Dot(const Vec3& right) const
	{
		return xx * right.xx + yy * right.yy + zz * right.zz;
	}
	float CrossMagnitude(const Vec3& right) const
	{
		return  xx * right.xx - yy * right.yy - zz * right.zz;
	}
	Vec3 Proj(const Vec3& right) const
	{
		return Vec3{ (right*(Dot(right)) / LengthSquared()) };
	}
	Vec3 Rej(const Vec3& right) const
	{
		return Vec3{ *this - Proj(right) };
	}

	float GetX();
	float GetY();
	float GetZ();

};

std::ostream& operator<<(std::ostream& os, Vec3 v);

#endif // ndef VEC3_H_