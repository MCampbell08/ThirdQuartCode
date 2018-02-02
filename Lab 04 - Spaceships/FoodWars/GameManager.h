#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Core.h"
#include "Spaceship.h"

class GameManager
{
public:
	GameManager();
public: //public non-static methods
	bool Initialize();
	bool Shutdown();
	bool RunGame();
	bool Update(float dt);
	void Draw(Core::Graphics& graphics);

	void CalcFps(float dt);

	void ShowFps(Core::Graphics & graphics);

public: //public static methods
	static bool UpdateCallBack(float dt) 
	{
		return m_manager->Update(dt);
	}
	static void DrawCallBack(Core::Graphics& graphics)
	{
		m_manager->Draw(graphics);
	}

	static const int screenWidth  = 900;
	static const int screenHeight = 600;
	int m_fps;
private: 
	static GameManager* m_manager;
	Spaceship m_ship;
};

#endif // ndef GAMEMANAGER_H_


