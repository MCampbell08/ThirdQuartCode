#include "GameManager.h"
#include "Spaceship.h"
#include "Core.h"

GameManager* GameManager::m_manager;

GameManager::GameManager(): m_ship(450, 300)
{
}

bool GameManager::Initialize()
{
	m_manager = this;
	Core::Init("Food Wars", screenWidth, screenHeight, 1000);
	Core::RegisterDrawFn(DrawCallBack);
	Core::RegisterUpdateFn(UpdateCallBack);
	return true;
}

bool GameManager::Shutdown()
{
	return true;
}

bool GameManager::RunGame()	
{
	Core::GameLoop();
	return true;
}

bool GameManager::Update(float dt)
{
	m_ship.Update(dt);
	CalcFps(dt);
	if (Core::Input::IsPressed(Core::Input::KEY_ESCAPE)) return true;
	return false;
}

void GameManager::Draw(Core::Graphics & graphics)
{
	m_ship.Draw(graphics, m_ship);
	ShowFps(graphics);
}

void GameManager::CalcFps(float dt)
{
	static float timeSpan = 0.0f;
	static int numFrames = 0;
	const int fraquency = 1;
	const float freqSpan = 1.0f / fraquency;

	++numFrames;
	timeSpan += dt;
	if (timeSpan >= freqSpan)
	{
		m_fps = numFrames*fraquency;
		numFrames = 0;
		timeSpan -= freqSpan;
	}
}

void GameManager::ShowFps(Core::Graphics & graphics)
{
	const int bufSize = 20;
	char timebuf[bufSize];
	sprintf_s(timebuf, bufSize, "FPS: %d", m_fps);
	graphics.SetColor(RGB(0, 255, 255));
	graphics.DrawString(screenWidth - 100, 0, timebuf);
}
