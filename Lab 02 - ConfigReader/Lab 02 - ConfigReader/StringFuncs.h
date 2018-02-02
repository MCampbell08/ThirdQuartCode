#pragma once

// Mason Campbell
// 5/17/16
// StrinFuncs.h
// Simple logging for games
class StringFuncs
{
public:
	static bool			StringsAreEqual (const char* const srt1,	const char* const str2);
	static bool			IsPalindrome	(const char* const str);
	static int			StringCompare	(const char* const str1,	const char* const str2);
	static int			StringLen		(const char* const str);
	static int			FindSubString	(const char* const source,	const char* const target);

public:
	static char*		StringReverse	(char* const str);
	static char*		ToLower			(char* const str);
	static int			StringCopy		(const char* const source, char* const target, int targetSize);

public:
	static char*		StringDup		(const char* const str);
	static char*		StringReverse	(const char* const str);
	static char*		StringConcat	(const char* const str1, const char* const str2, const char* sep = "");
	static char*		ToLower			(const char* const str);
};

