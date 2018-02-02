#ifndef VEC2_H_
#define VEC2_H_

#include <ostream>
#include "GameLogger.h"

// This is an immutable Vector 2D class
class Vec2
{
public:
	float xx, yy;

public:
	Vec2() : xx(0), yy(0) {}
	Vec2(float xx, float yy) : xx(xx), yy(yy) {}
	Vec2 operator+ (const Vec2& right) const
	{
		return Vec2{ xx + right.xx, yy + right.yy };
	}
	Vec2 operator- (const Vec2& right) const
	{
		return Vec2{ xx - right.xx, yy - right.yy };
	}
	Vec2 operator- () const
	{
		return Vec2{ -xx, -yy };
	}
	Vec2 operator* (const Vec2& right) const
	{
		return Vec2{ xx * right.xx, yy * right.yy };
	}
	Vec2 operator* (const float right) const
	{
		return Vec2{ xx * right, yy * right };
	}
	Vec2 operator/ (const float right) const
	{
		if (right == 0)
		{
			GameLogger::Log(LogMsgType::Error, "Error: Divide by zero.");
		}
		return Vec2{ xx / right, yy / right };
	}
	Vec2 Vec2::Lerp(const Vec2 start, const Vec2 end, const float point) const
	{
		return Vec2{ start + (end - start)*point };
	}

	float Vec2::Length() const
	{
		return sqrt(LengthSquared());
	}

	float Vec2::LengthSquared()const
	{
		return xx * xx + yy * yy;
	}

	Vec2 Vec2::Normalize() const
	{
		float len = Length();
		if (len == 0)
		{
			return Vec2(0, 0);
		}
		else
		{
			return Vec2{ xx / len, yy / len };
		}
	}

	Vec2 Vec2::PerpCW() const
	{
		return Vec2{ yy, -xx };
	}
	Vec2 Vec2::PerpCCW() const
	{
		return Vec2{ -yy, xx };
	}
	float Vec2::Dot(const Vec2& right) const
	{
		return xx * right.xx + yy * right.yy;
	}
	float Vec2::CrossMagnitude(const Vec2& right) const
	{
		return  xx * right.xx - yy * right.yy;
	}
	Vec2 Vec2::Proj(const Vec2& right) const
	{
		return Vec2{ (right*(Dot(right)) / LengthSquared()) };
	}
	Vec2 Vec2::Rej(const Vec2& right) const
	{
		return Vec2{ *this - Proj(right) };
	}
	float GetX();
	float GetY();
};

std::ostream& operator<<(std::ostream& os, Vec2 v);

#endif // ndef VEC2_H_
