#include "Vec3.h"

std::ostream & operator<<(std::ostream & os, Vec3 v)
{
	return os << "(" << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ")\n";
}

float Vec3::GetX()
{
	return xx;
}

float Vec3::GetY()
{
	return yy;
}

float Vec3::GetZ()
{
	return zz;
}
