#include <iostream>
#include "Engine.h"
#include "RenderUI.h"
#include "Tab.h"
#include "ConfigReader.h"
#include "GameLogger.h"


int main(int argc, char** argv)
{
	printf("Hello, from 2D Calculator!\n");
	if (!GameLogger::Initialize("..\\Debug\\", "2DCalculator.log")) return -1;
	ConfigReader conf;
	if (!conf.Initialize("..\\Debug\\2DCalculator.config", nullptr)) return -1;
	RenderUI renderUI;
	if (!Tab::Initialize(&renderUI, conf)) return -1;

	
	if (!renderUI.initialize(argc, argv)) return -1;

	int runResult = renderUI.run();

	renderUI.shutdown();
	if (!conf.Shutdown()) return -1;
	if (!GameLogger::Shutdown()) return -1;

	return runResult;
}