#ifndef FILEPATH_H_
#define FILEPATH_H_

// Mason Campbell
// 5/3/16
// Filepath.h
// Class to make it easy to time-stamp filepath

class Filepath
{
public:
	static char* Create(char* const buffer, int bufSize, const char* const path, const char* const stamp, const char* const filename);
};


#endif // ndef FILEPATH_H_

