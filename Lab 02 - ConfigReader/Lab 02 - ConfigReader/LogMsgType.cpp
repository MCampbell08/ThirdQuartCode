#include "LogMsgType.h"

char* LogMsgWords[] =
{
	"Process:",
	"Info:",
	"Debug:",
	"Warning:",
	"Error:",
	"Fatal Error:"
	"Programmer Error:"
};

std::ostream & operator<<(std::ostream & os, LogMsgType msgType)
{
	return os << LogMsgWords[int(msgType)];
}
