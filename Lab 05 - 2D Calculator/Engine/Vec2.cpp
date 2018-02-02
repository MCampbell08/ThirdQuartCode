#include "Vec2.h"

std::ostream & operator<<(std::ostream & os, Vec2 v)
{
	return os << "(" << v.xx << ", " << v.yy << ")\n";
}

float Vec2::GetX()
{
	return xx;
}

float Vec2::GetY()
{
	return yy;
}
