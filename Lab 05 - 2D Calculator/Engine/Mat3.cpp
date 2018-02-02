#include "Mat3.h"



std::ostream & operator<<(std::ostream & os, Mat3 m)
{
	return os << "[" << m.topleft	 << ", " << m.topmiddle	   << ", " << m.topright    << "]\n"
			  << "[" << m.middleleft << ", " << m.middlemiddle << ", " << m.middleright << "]\n"
			  << "[" << m.bottomleft << ", " << m.bottommiddle << ", " << m.bottomright << "]\n";
}
