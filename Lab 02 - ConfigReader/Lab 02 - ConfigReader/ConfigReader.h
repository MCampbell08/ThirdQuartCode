#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_

// Mason Campbell
// 5/4/2016
// ConfigReader.h
// Class that reads in a configuration file and stores
// the key-value pairs that it finds there

#include "KeyValuePairs.h"
#include <fstream>

class ConfigReader
{
public:
	ConfigReader();
	~ConfigReader();

public: // public methods
	bool Initialize(const char* const filename, const char* const key = nullptr);
	bool Shutdown();

	bool IsFull             () const;                      // returns true if no room left for new keys
	bool ContainsKey	    (const char* const key) const; // return true if key is found
	bool ContainsRequiredKey(const char* const key);	 //calls [ContainsKey();]  

												   // return false if key already found, otherwise add the KVP and return true
	bool AddUnique(const char* const key, const char* const value);

	// returns true if key found and fills in value
	bool GetStringForKey (const char* const key, const char*& outValue)	;
	bool GetIntForKey    (const char* const key, int&         outValue);
	bool GetFloatForKey  (const char* const key, float&       outValue);

	bool isComment   (const char &key);
private:
	friend std::ostream& operator<<(std::ostream& os, ConfigReader& kvps);

private:
	KeyValuePairs m_db; // database of kvps
	std::ifstream m_confStream;
};

// nicely prints out the entire list of keys. Begin KeyValuePairs / End KeyValuePairs
std::ostream& operator<<(std::ostream& os, ConfigReader& kvps);

#endif // ndef CONFIGREADER_H_
