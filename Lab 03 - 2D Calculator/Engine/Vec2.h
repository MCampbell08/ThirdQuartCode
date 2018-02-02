#ifndef VEC2_H_
#define VEC2_H_

#include <ostream>
#include "GameLogger.h"

// This is an immutable Vector 2D class
class Vec2
{
public:
	float xy[2];

public:
	Vec2(float x, float y) : xy{ x, y } {}
	Vec2 operator+ (const Vec2& right) const
	{
		return Vec2{ xy[0] + right.xy[0], xy[1] + right.xy[1] };
	}
	Vec2 operator- (const Vec2& right) const
	{
		return Vec2{ xy[0] - right.xy[0], xy[1] - right.xy[1] };
	}
	Vec2 operator- () const
	{
		return Vec2{ -xy[0], -xy[1] };
	}
	Vec2 operator* (const Vec2& right) const
	{
		return Vec2{ xy[0] * right.xy[0], xy[1] * right.xy[1] };
	}
	Vec2 operator* (const float right) const
	{
		return Vec2{ xy[0] * right, xy[1] * right };
	}
	Vec2 operator/ (const float right) const
	{
		if (right == 0)
		{
			logger.Log(LogMsgType::Error, "Error: Divide by zero.");
		}
		return Vec2{ xy[0] / right, xy[1] / right };
	}
	Vec2 Lerp(const Vec2 start, const Vec2 end, const float point) const
	{
		return Vec2{ start + (end - start)*point };
	}
	float Length() const
	{
		return sqrt(LengthSquared());
	}
	float LengthSquared() const
	{
		return xy[0] * xy[0] + xy[1] * xy[1];
	}
	Vec2 Normalize() const
	{
		float len = Length();
		if (len == 0)
		{
			return Vec2(0, 0);
		}
		else
		{
			return Vec2{ xy[0] / len, xy[1] / len };
		}
	}
	Vec2 PerpCW() const
	{
		return Vec2{ xy[1], -xy[0] };
	}
	Vec2 PerpCCW() const
	{
		return Vec2{ -xy[1], xy[0] };
	}
	float Dot(const Vec2& right) const
	{
		return xy[0] * right.xy[0] + xy[1] * right.xy[1];
	}
	float CrossMagnitude(const Vec2& right) const
	{
		return  xy[0] * right.xy[0] - xy[1] * right.xy[1];
	}
	Vec2 Proj(const Vec2& right) const
	{
		return Vec2{ (right*(Dot(right)) / LengthSquared()) };
	}
	Vec2 Rej(const Vec2& right) const
	{
		return Vec2{ *this - Proj(right) };
	}

private:
	GameLogger logger;

};

std::ostream& operator<<(std::ostream& os, Vec2 v);

#endif // ndef VEC2_H_
