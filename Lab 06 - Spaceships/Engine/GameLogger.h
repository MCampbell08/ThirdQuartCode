#ifndef GAMELOGGER_H_
#define GAMELOGGER_H_

// Mason Campbell
// 5/3/16
// GameLogger.h
// Simple logging for games

#include <fstream>
#include <time.h>
#include "LogMsgType.h"
#include "Engine.h"

ENGINE_TEMPLATE template class ENGINE_SHARED std::basic_filebuf<char, std::char_traits<char>>;
ENGINE_TEMPLATE template class ENGINE_SHARED std::basic_ofstream<char, std::char_traits<char>>;

class ENGINE_SHARED GameLogger
{
public: // public static methods
	static bool Initialize (const char* const path, const char* const filename);
	static bool Shutdown   ();

	template<typename...Args>
	static void Log(LogMsgType msg, const char* const format, Args... args);

private: // private static methods
	static void		   WriteLog  (LogMsgType msgType, const char* const msg); // pre-pend time, error level, etc
	static char*	   TimeFunc  (const char* const str);
	static LogMsgType  GetMsg    (LogMsgType msg);
	static void		   ShowStats (std::ostream& os);

private: // private static data
	static std::ofstream m_logStream;
	static int			 m_counts[int(LogMsgType::NumTypes)];
};

template<typename ...Args>
inline void GameLogger::Log(LogMsgType msg, const char * const format, Args ...args)
{
	const int bufSize = 400;
    char buffer[bufSize];
    sprintf_s (buffer, bufSize, format, args...);
    WriteLog (msg, buffer);
}

#endif // ndef GAMELOGGER_H_
