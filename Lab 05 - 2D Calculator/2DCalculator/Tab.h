#pragma once
#include "ConfigReader.h"

class RenderUI;
class Tab
{
public:
	static bool Initialize(RenderUI* render, ConfigReader& conf);
	static bool Shutdown();
	static bool CheckKey(const char* const key);
	static ConfigReader& m_conf;
};

