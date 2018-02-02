#ifndef LOGMSGTYPE_H_
#define LOGMSGTYPE_H_

// Mason Campbell
// 5/3/16
// LogMsgType.h
// Enum Class for the different types of type messages

#include <ostream>

enum class LogMsgType
{
	Process, Info, Debug, Warning, Error, FatalError

	, NumTypes // this one is always last

};

std::ostream& operator<<(std::ostream & os, LogMsgType msgType);

#endif // ndef LOGMSGTYPE_H_

