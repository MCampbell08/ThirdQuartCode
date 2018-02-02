#include "KeyValuePair.h"
#include <iomanip>

KeyValuePair::KeyValuePair()
{
}

KeyValuePair::KeyValuePair(const char * const key, const char * const value)
{
	strcpy_s(m_key, maxChars, key);
	strcpy_s(m_value, maxChars, value);
}


KeyValuePair::~KeyValuePair()
{
}

std::ostream & operator<<(std::ostream & os, KeyValuePair & kvp)
{
	return os << "{KVP} " << std::setw(6) << "[" << kvp.m_key << "] " << "[" << kvp.m_value << "]\n";
}
