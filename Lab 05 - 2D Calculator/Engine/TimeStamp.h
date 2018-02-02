#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

// Mason Campbell
// 5/5/16
// TimeStamp.h
// Class to make it easy to time-stamp filepath

#include <ostream>

class TimeStamp
{
public:
	static const char* GetStamp(char* const buffer, int bufSize, bool useColons = false);
};

std::ostream& operator << (std::ostream& os, TimeStamp& stamp);

#endif // ndef TIMESTAMP_H_


