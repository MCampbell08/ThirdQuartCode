#include "Vec2.h"

float Vec2::GetX()
{
	return xx;
}

float Vec2::GetY()
{
	return yy;
}

std::ostream & operator<<(std::ostream & os, Vec2 v)
{
	return os << "(" << v.xx << ", " << v.yy << ")\n";
}
