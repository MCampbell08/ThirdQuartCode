#include "TimeStamp.h"
#include <string.h>
#include <time.h>
#include <sys/timeb.h>


const char * TimeStamp::GetStamp(char* const buffer, int bufSize, bool useColons)
{
	const char* const format = useColons ? "%F %T." :"%F %H-%M-%S.";

	//get milliseconds
	const int milliSize = 4;
	char millibuf[milliSize];
	struct _timeb timebuffer;
	_ftime64_s (&timebuffer);
	unsigned short millitime = timebuffer.millitm;
	sprintf_s(millibuf, milliSize, "%03d", millitime);

	//get date and time
	time_t rawtime;
	time(&rawtime);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime); // TODO: check error value
	strftime(buffer, bufSize, format, &timeinfo);
	strcat_s(buffer, bufSize, millibuf);

	return buffer;
}

std::ostream & operator<<(std::ostream & os, TimeStamp & stamp)
{
	stamp;
	const int stampSize = 80;
	char stampbuf[stampSize];
	return os << stamp.GetStamp(stampbuf, stampSize, true);
}
