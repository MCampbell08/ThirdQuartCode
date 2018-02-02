#include "Tab.h"
#include "ConfigReader.h"
#include "GameLogger.h"
#include "AdditionTab.h"
#include "PerpendicularTab.h"
#include "DotProductTab.h"
#include "LerpTab.h"

bool Tab::Initialize(RenderUI* renderUI, ConfigReader& conf)
{
	const char* addKey  = "2DCalculator.AdditionTab";
	const char* dotKey  = "2DCalculator.DotProductTab";
	const char* lerpKey = "2DCalculator.LerpTab";
	const char* perpKey = "2DCalculator.PerpendicularTab";

	if (conf.ContainsRequiredKey(addKey))
	{
		if (conf.GetBoolForKey(addKey))
		{
			(AdditionTab::Initialize(renderUI)) ? GameLogger::Log(LogMsgType::Process, "2DCalculator.AdditionTab::Initialize() successful\n")
				: GameLogger::Log(LogMsgType::Process, "2DCalculator.AdditionTab::Initialize() not successful\n");
		}
		if (conf.GetBoolForKey(dotKey))
		{
			(DotProductTab::Initialize(renderUI)) ? GameLogger::Log(LogMsgType::Process, "2DCalculator.DotProductTab::Initialize() successful\n")
				: GameLogger::Log(LogMsgType::Process, "2DCalculator.DotProductTab::Initialize() not successful\n");
		}
		if (conf.GetBoolForKey(lerpKey))
		{
			(LerpTab::Initialize(renderUI)) ? GameLogger::Log(LogMsgType::Process, "2DCalculator.LerpTab::Initialize() successful\n")
				: GameLogger::Log(LogMsgType::Process, "2DCalculator.LerpTab::Initialize() not successful\n");
		}
		if (conf.GetBoolForKey(perpKey))
		{
			(PerpendicularTab::Initialize(renderUI)) ? GameLogger::Log(LogMsgType::Process, "2DCalculator.PerpendicularTab::Initialize() successful\n")
				: GameLogger::Log(LogMsgType::Process, "2DCalculator.PerpendicularTab::Initialize() not successful\n");
		}
	}

	GameLogger::Log(LogMsgType::Process, "2DCalculator.Tab::Initialize() successful\n");
	return true;
}

bool Tab::Shutdown()
{
	AdditionTab::Shutdown();		GameLogger::Log(LogMsgType::Process, "2DCalculator.AdditionTab::Shutdown() successful\n");
	PerpendicularTab::Shutdown();	GameLogger::Log(LogMsgType::Process, "2DCalculator.PerpendicularTab::Shutdown() successful\n");
	DotProductTab::Shutdown();		GameLogger::Log(LogMsgType::Process, "2DCalculator.DotProductTab::Shutdown() successful\n");
	LerpTab::Shutdown();			GameLogger::Log(LogMsgType::Process, "2DCalculator.LerpTab::Shutdown() successful\n");
	
	GameLogger::Log(LogMsgType::Process, "2DCalculator.Tab::Shutdown() successful\n");
	return true;
}

bool Tab::CheckKey(const char * const key)
{
	ConfigReader conf;
	if (conf.ContainsRequiredKey(key))
	{
		if (conf.GetBoolForKey(key))
		{
			return true;
		}
	}
	return false;
}
