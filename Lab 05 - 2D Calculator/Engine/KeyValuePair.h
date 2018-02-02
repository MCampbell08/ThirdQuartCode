#ifndef KEYVALUEPAIR_H_
#define KEYVALUEPAIR_H_

// Mason Campbell
// 5/5/2016
// KeyValuePair.h
// Simple class to hold keys and values in strings

#include <ostream>
#include "Engine.h"

class ENGINE_SHARED KeyValuePair
{
public:
	KeyValuePair();
	KeyValuePair(const char* const key, const char* const value);
	~KeyValuePair();

public: // data members
	static const int  maxChars = 48;
				 char m_key[maxChars];
				 char m_value[maxChars];
};

// {KVP} [Key] [Value]
std::ostream& operator<<(std::ostream& os, KeyValuePair& kvp);

#endif // ndef KEYVALUEPAIR_H_
