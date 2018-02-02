#include <iostream>
#include "Spaceship.h"
#include "GameManager.h"
#include "GameLogger.h"
#include "ConfigReader.h"
#include "Vec2.h"
#include "Core.h"

int main()
{	
	printf("Hello from FoodWars!\n");
	GameManager game;
	if (!game.Initialize()) return -1;
	game.RunGame();
	if (!GameLogger::Initialize("..\\Debug\\", "FoodWars.log")) return -1;
	ConfigReader conf;
	if (!conf.Initialize("..\\Debug\\FoodWars.config", nullptr)) return -1;

	return 0;
}