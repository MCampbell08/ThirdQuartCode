#include "GameLogger.h"
#include "ConfigReader.h"

int main()
{
	ConfigReader conf;
	if (!GameLogger::Initialize("..\\Debug\\", "CreepGame.log")) return 1;
	if (!conf.Initialize("..\\Debug\\CreepGame.config", nullptr)) return 1;

	if (!conf.Shutdown()) return 2;
	if (!GameLogger::Shutdown()) return 2;
	return 0;
}