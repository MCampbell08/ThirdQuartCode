#include "GameLogger.h"
#include "string.h"
#include "LogMsgType.h"
#include "Filepath.h"
#include "TimeStamp.h"
#include <iostream>
#include <iomanip>

std::ofstream GameLogger::m_logStream;
int           GameLogger::m_counts[int(LogMsgType::NumTypes)]{ 0 };
TimeStamp t;

bool GameLogger::Initialize(const char * const path, const char * const filename)
{
	const int pathsize = 512;
	char filepath[pathsize];

	const int stampSize = 80;
	char stampbuf[stampSize];
	TimeStamp::GetStamp(stampbuf, stampSize, false);

	Filepath::Create(filepath, pathsize, path, stampbuf, filename);

	m_logStream.open(filepath, std::ios::out | std::ios::trunc);

	m_logStream << t << "[" << std::setw(10) << std::left <<  GetMsg(LogMsgType::Process) << "]" << "GameLogger::Initialize() opened log file [" << filepath << "] for writing.\n";
	if (m_logStream)
	{
		WriteLog(GetMsg(LogMsgType::Info), "GameLogger::Initialize() successful\n");
		return true;
	}
	else
	{
		WriteLog(GetMsg(LogMsgType::FatalError), "GameLogger::Initialize() not successful\n");
		return false;
	}
}

bool GameLogger::Shutdown()
{
	if (m_logStream)
	{
		WriteLog(GetMsg(LogMsgType::Info), "GameLogger::Shutdown() successful\n");
		m_logStream.close();
		ShowStats(std::cout);
		return true;
	}
	else
	{
		WriteLog(GetMsg(LogMsgType::FatalError), "GameLogger::Shutdown() not successful\n");
		return false;
	}
}

void GameLogger::WriteLog(LogMsgType msgType, const char * const msg)
{
	if (m_logStream)
	{
		m_logStream << std::setw(3) << t <<  "[" << std::setw(10) << std::left << msgType << "]" << msg;
	}
	else {
		msgType = LogMsgType::FatalError;
		m_logStream << t << std::setw(3) << "[" << std::setw(10) << std::left << msgType << "]" << "Unable to write to file!" << msg;
	}
	m_counts[int(msgType)] += 1;
}

char * GameLogger::TimeFunc(const char* const str)
{
	time_t rawTime;
	tm timeInfo; 
	const int buffSize = 100;
	char buffer[buffSize];
	
	time(&rawTime);
	localtime_s (&timeInfo, &rawTime);
	strftime(buffer, buffSize, str, &timeInfo);

	return _strdup(buffer);
}

LogMsgType GameLogger::GetMsg(LogMsgType msg)
{
	switch (msg)
	{
	case LogMsgType::Process:
		break;
	case LogMsgType::Debug:
		break;
	case LogMsgType::Error:
		break;
	case LogMsgType::FatalError:
		break;
	case LogMsgType::Warning:
		break; 
	case LogMsgType::Info:
		break;
	}
	return msg;
}

void GameLogger::ShowStats(std::ostream & os)
{
	std::cout << "Begin Log Message by Type\n";
	for (int j = 0; j < (int)LogMsgType::NumTypes; ++j)
	{
		if (m_counts[j] > 0)
		{
			os << "[" << std::setw(10) << std::left << GetMsg(static_cast <LogMsgType> (j)) << "] = " << m_counts[j] << std::endl;
		}
	}
	std::cout << "End Log Message by Type\n";
}

