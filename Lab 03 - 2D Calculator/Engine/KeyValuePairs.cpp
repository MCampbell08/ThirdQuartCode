#include "KeyValuePairs.h"
#include "StringFuncs.h"
#include "GameLogger.h"
#include <iomanip>


KeyValuePairs::KeyValuePairs()
{
}


KeyValuePairs::~KeyValuePairs()
{
}

bool KeyValuePairs::IsFull() const
{
	if (m_numKeys == maxKeys)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool KeyValuePairs::ContainsKey(const char * const key) const
{
	for (int j = 0; j < maxKeys; ++j)
	{
		if (StringFuncs::StringsAreEqual(m_kvPairs[j].m_key, key))
		{
			return true;
		}
	}
	return false;
}

bool KeyValuePairs::AddUnique(const char * const key, const char * const value)
{
	if (ContainsKey(key))
	{
		return false;
	}
	if (AddKeyValue(key, value))
	{
		return true;
	}
	return false;
}

const char * KeyValuePairs::GetValueForKey(const char * const key) const
{
	for (int j = 0; j < maxKeys; ++j)
	{
		if (StringFuncs::StringsAreEqual(m_kvPairs[j].m_key, key))
		{
			return m_kvPairs[j].m_value;
		}
	}
	return nullptr;
}

bool KeyValuePairs::AddKeyValue(const char * const key, const char * const value)
{
	if (IsFull())
	{
		GameLogger::Log(LogMsgType::FatalError, "ConfigReader::Initialize() ran out of room for keys! Exiting program!\n");
		return false;
	}
	else 
	{
		m_kvPairs[m_numKeys] = KeyValuePair(key, value);
		++m_numKeys;
		return true;
	}
}

std::ostream & operator<<(std::ostream & os, KeyValuePairs & kvps)
{
	os << "Begin Key-Value Pairs\n";
	for (int j = 0; j < kvps.m_numKeys; ++j)
	{
		os << " " << std::setw(3) << j << " " << kvps.m_kvPairs[j] << "\n";
	}
	os << "End Key-Value Pairs\n";
	return os;
}
