#include "ConfigReader.h"
#include "GameLogger.h"
#include "StringFuncs.h"
#include <string.h>
#include <iostream>
#include <fstream>

std::ifstream m_confStream;

ConfigReader::ConfigReader()
{
}

ConfigReader::~ConfigReader()
{
}

bool ConfigReader::Initialize(const char * const filename, const char * const key)
{
	GameLogger::Log(LogMsgType::Info, "GameLogger::Initialize() opened log file [%s] for reading.\n", filename);
	key;
	const int bufSize = 100;
	char buffer[bufSize];
	char* next = buffer;
	char keyChars [bufSize / 2];
	char valChars [bufSize / 2];
	bool valTurn = false;
	bool firstQuote = false;
	bool firstComment = true;
	bool noVal = false;
	bool moreQuotesFound = false;
	bool afterSpace = false;
	int whiteSpaceCounter = 0;
	
	m_confStream.open(filename);
	if (m_confStream)
	{
		while (m_confStream.getline(buffer, bufSize))
		{
			whiteSpaceCounter = 0;
			char* keyP = keyChars;
			char* valP = valChars;
			int keyLength = 0;
			moreQuotesFound = false;
			if (IsFull()) break;
			if (strlen(buffer) == 0) continue;
			next = buffer;
			for (size_t j = 0; j < strlen(buffer) + 1; ++j)
			{
				if (isComment(*next))
				{
					if (keyLength == 0)
					{
						valTurn = false;
						break;
					}

				}
				if (firstQuote)
				{	
					*next--;
					for (size_t l = j - 1; l < strlen(buffer); ++l)
					{
						char tmp = *next;
						*valP = tmp;
						++valP;
						++next; 
						if (*next == '"')
						{
							++next;
							if(isspace((int)*next))
							{ 
								++valP;
								*valP = '\0';
								if (!ContainsRequiredKey(keyChars))
								{
									AddUnique(keyChars, valChars);
									GameLogger::Log(LogMsgType::Info, "	Added KVP (%s, %s)\n", keyChars, valChars);
								}
								else
								{
									GameLogger::Log(LogMsgType::Error, "Duplicate Key found (%s, %s)\n", keyChars, valChars);
								}
								firstQuote = false;
								valTurn = false;
								firstComment = true;
								break;
							}
							--next;
						}
						if (*next == '/')
						{
							*valP = '\0';
							if (!ContainsRequiredKey(keyChars))
							{
								AddUnique(keyChars, valChars);
								GameLogger::Log(LogMsgType::Info, "	Added KVP (%s, %s)\n", keyChars, valChars);
							}
							else
							{
								GameLogger::Log(LogMsgType::Error, "Duplicate Key found (%s, %s)\n", keyChars, valChars);
							}
							firstQuote = false;
							valTurn = false;
							firstComment = true;
							break;
						}
						if (l == strlen(buffer) - 1 && *next == '\0')
						{	
							*valP = '\0';
							if (!ContainsRequiredKey(keyChars))
							{
								AddUnique(keyChars, valChars);
								GameLogger::Log(LogMsgType::Info, "	Added KVP (%s, %s)\n", keyChars, valChars);
							}
							else
							{
								GameLogger::Log(LogMsgType::Error, "Duplicate Key found (%s, %s)\n", keyChars, valChars);
							}
							firstQuote = false;
							valTurn = false;
							firstComment = true;
						}
						else if (l == (strlen(buffer) - 1)  && *next != '\"')
						{
							GameLogger::Log(LogMsgType::Error, "Missing End Quote On ConfigLine (%s)\n", buffer);
						}
					}
					break;
				}
				else if (isspace((int)*next) && !firstQuote || *next == '\0' && !firstQuote)
				{
					next -= keyLength;	
					if (!valTurn)
					{
						for (int k = 0; k < keyLength; ++k)
						{
							char tmp = *next;
							*keyP = tmp;
							++keyP;
							++next;
							if (isspace((int)*next) || *next == '\0')
							{

								if (*next == '\0')
								{
									*keyP = '\0';
									GameLogger::Log(LogMsgType::Error, "Key found without Value on ConfigLine (%s) in file (%s)\n", keyChars, filename);
									valTurn = false;
									firstComment = true;
									noVal = true;
									break;
								}
								else
								{
									*keyP = '\0';
									valTurn = true;
									firstComment = true;
									noVal = true;
								}
							}
						}
					}
					else if (valTurn)
					{
						for (int k = 0; k < keyLength; ++k)
						{
							char tmp = *next;
							*valP = tmp;
							++valP;
							++next;
							if (*next == ' ')
							{
								++next;
								if (*next != ' ') afterSpace = true;
								else afterSpace = false;
								--next;
							}
							if (*next == '/')
							{
								*valP = '\0';
								if (!ContainsRequiredKey(keyChars))
								{
									if (moreQuotesFound)
									{
										GameLogger::Log(LogMsgType::Warning, "Quote(s) found in value (%s) in file (%s)\n", buffer, filename);
									}
									AddUnique(keyChars, valChars);
									GameLogger::Log(LogMsgType::Info, "	Added KVP (%s, %s)\n", keyChars, valChars);
								}
								else
								{
									GameLogger::Log(LogMsgType::Error, "Duplicate Key found (%s, %s)\n", keyChars, valChars);
								}
								break;
							}
							if (isspace((int)*next) && k == keyLength - 1 || *next == '\0' && k == keyLength - 1)
							{
								if (afterSpace)
								{
									GameLogger::Log(LogMsgType::Error, "More found on Config line (%s) in file (%s)\n", buffer, filename); 
									valTurn = false;
									firstComment = true;
									break;
								}
								if (moreQuotesFound)
								{
									GameLogger::Log(LogMsgType::Warning, "Quote(s) found in value (%s) in file (%s)\n", buffer, filename);
								}
								*valP = '\0';
								if (!ContainsRequiredKey(keyChars))
								{
									AddUnique(keyChars, valChars);
									GameLogger::Log(LogMsgType::Info, "	Added KVP (%s, %s)\n", keyChars, valChars);
								}
								else
								{
									GameLogger::Log(LogMsgType::Error, "Duplicate Key found (%s, %s)\n", keyChars, valChars);
								}
							}
							valTurn = false;
							firstComment = true;
						}
					}
					keyLength = 0;
				}
				else {
					if (keyLength == 0 && !valTurn) 
					{
						char tmp = *next;
						*keyP = tmp;
						firstComment = false;
					}
					else if (keyLength == 0 && valTurn)
					{
						if (*next == '\"' && keyLength == 0)
						{
							firstQuote = true;
						}
						else if (*next == '\"' && keyLength != 0)
						{
							moreQuotesFound = true;
						}
						char tmp = *next;
						*valP = tmp;
					}
					++keyLength;
				}
				*next++;
				if (afterSpace)
				{
					afterSpace = false;
					break;
				}
			}
		}
		GameLogger::Log(LogMsgType::Process, "ConfigReader::Initialize successful\n");
		return true;
	}
	else 
	{
		GameLogger::Log(LogMsgType::FatalError, "ConfigReader::Initialize not successful\n");
		return false;
	}

}

bool ConfigReader::Shutdown()
{
	if (m_confStream.is_open())
	{
		GameLogger::Log(LogMsgType::Process, "ConfigReader::Shutdown() successful\n");
		m_confStream.close();
		return true;
	}
	else
	{
		GameLogger::Log(LogMsgType::FatalError, "ConfigReader::Shutdown() not successful\n");
		return false;
	}
}

bool ConfigReader::IsFull() const
{
	if (m_db.IsFull())
	{
		return true;
	}
	return false;
}

bool ConfigReader::ContainsKey(const char * const key) const
{
	if (m_db.ContainsKey(key))
	{
		return true;
	}
	return false;
}

bool ConfigReader::ContainsRequiredKey(const char * const key)
{
	if (m_db.ContainsKey(key))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ConfigReader::AddUnique(const char * const key, const char * const value)
{
	if (m_db.AddUnique(key, value))
	{
		return true;
	}
	return false;
}

bool ConfigReader::GetStringForKey(const char * const key, const char *& outValue)
{
	if (m_db.ContainsKey(key))
	{
		const char* keyP = m_db.GetValueForKey(key);
		outValue = keyP;
		return true;
	}
	return false;
}

bool ConfigReader::GetIntForKey(const char * const key, int & outValue)
{
	if (m_db.ContainsKey(key))
	{
		int tmp = atoi(m_db.GetValueForKey(key));
		outValue = tmp;
		return true;
	}
	return false;
}

bool ConfigReader::GetFloatForKey(const char * const key, float & outValue)
{
	if (m_db.ContainsKey(key))
	{
		float tmp =(float) atof(m_db.GetValueForKey(key));
		outValue = tmp;
		return true;
	}
	return false;
}

bool ConfigReader::GetBoolForKey(const char * const key)
{
	const char* value = nullptr;
	GetStringForKey(key, value);
	if (StringFuncs::StringsAreEqual(value, "true")) return true;	
	return false;
}


bool ConfigReader::isComment(const char & key)
{
	if (key == '/') return true;
	return false;
}

std::ostream & operator<<(std::ostream & os, ConfigReader & kvps)
{
	return os << kvps.m_db;
}
