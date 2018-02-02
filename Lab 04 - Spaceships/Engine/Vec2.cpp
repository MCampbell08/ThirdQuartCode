#include "Vec2.h"

std::ostream & operator<<(std::ostream & os, Vec2 v)
{
	return os << "(" << v.xy[0] << ", " << v.xy[1] << ")\n";
}
