#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "Vec2.h"
#include "Core.h"

class Spaceship
{
public:
	Spaceship(float x, float y);

public:
	bool Update(float dt);
	void Draw(Core::Graphics& graphics, Spaceship& ship);
	bool CheckWrap();
	bool CheckBounce();
	bool CheckACollision();
	void ChangeSettings();

private:
	void DrawLine(Core::Graphics& graphics, const Vec2& p1, const Vec2& p2);
	void DrawShip(Core::Graphics& graphics, Spaceship& ship);
	void InitializePoints();
	void InitializeEnemy();
	void InitializeEnemyPoints();
	void DrawDiamond(Core::Graphics & graphics, Spaceship & ship);
	void DrawEnemy(Core::Graphics & graphics, Spaceship & ship);
	void DrawEnemyPath(Core::Graphics & graphics, Spaceship & ship);
	float GetPercentage();

private:
	Vec2 m_shipshape[21];
	Vec2 m_diamondshape[2];
	Vec2 m_enemyshape[9];
	Vec2 m_enemypath[6];
	Vec2 m_turret[2];
	Vec2 m_position;
	Vec2 m_diamondposition;
	Vec2 m_enemyposition;
	Vec2 m_enemypathorigin;
	Vec2 m_velocity = m_position;
	Vec2 m_point1 = m_enemypath[0];
	Vec2 m_point2 = m_enemypath[1];
	bool m_side1And2 = true;
	bool m_side3And4 = true;
	float m_timer = 0;
	float m_percent = 0;
	float m_enemyspeed = 50;
	float m_speed = 400;
	bool m_wrap = true;
	bool m_bounce = false;
};

#endif // ndef SPACESHIP_H_