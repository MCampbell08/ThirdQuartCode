#include "Spaceship.h"
#include "Core.h"
#include "GameManager.h"
#include "GameLogger.h"

Spaceship::Spaceship(float x, float y)
{
	m_position = { x,y };
	m_diamondposition = { GameManager::screenWidth / 2, GameManager::screenHeight / 2 };
	m_enemypathorigin = m_diamondposition;
	m_turret[0] = m_position;
	m_turret[1] = m_position - Vec2{ 0, 10 }; 
	InitializeEnemy();	
	InitializePoints();
	InitializeEnemyPoints();
}

bool Spaceship::Update(float dt)
{	
	if (Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		m_velocity = Vec2{ 0,-1 }*(dt * m_speed);
		m_position = m_position + m_velocity;
		m_turret[1] = m_position + m_velocity;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
	{
		m_velocity = Vec2{ 1,0 }*(dt * m_speed);
		m_position = m_position + m_velocity;
		m_turret[1] = m_position + m_velocity;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
	{
		m_velocity = Vec2{ -1,0 }*(dt * m_speed);
		m_position = m_position + m_velocity;
		m_turret[1] = m_position + m_velocity;
	}
	if (Core::Input::IsPressed(Core::Input::KEY_DOWN))
	{
		m_velocity = Vec2{ 0,1 }*(dt * m_speed);
		m_position = m_position + m_velocity;
		m_turret[1] = m_position + m_velocity;
	}
	if (Core::Input::IsPressed(Core::Input::BUTTON_RIGHT))
	{
		m_turret[1] = ((Vec2{ (float)Core::Input::GetMouseX(), (float)Core::Input::GetMouseY() }) - m_position).Normalize() * 10.0f + m_position;
	}
	m_turret[0] = m_position;
	CheckWrap();
	CheckBounce();
	ChangeSettings(); 
	CheckACollision();
	m_timer += dt;
	if (m_side1And2 && m_side3And4)
	{
		m_enemyposition = m_enemypath[0].Lerp(m_enemypath[0], m_enemypath[1], GetPercentage());
		if (GetPercentage() >= 1.0f) m_side1And2 = false;
	}
	else if (!m_side1And2 && m_side3And4)
	{
		m_enemyposition = m_enemypath[1].Lerp(m_enemypath[1], m_enemypath[2], GetPercentage());
		if (GetPercentage() >= 1.0f) m_side3And4 = false;
	}
	else if (!m_side1And2 && !m_side3And4)
	{
		m_enemyposition = m_enemypath[2].Lerp(m_enemypath[2], m_enemypath[3], GetPercentage());
		if (GetPercentage() >= 1.0f) m_side1And2 = true;
	}
	else if (m_side1And2 && !m_side3And4)
	{
		m_enemyposition = m_enemypath[3].Lerp(m_enemypath[3], m_enemypath[4], GetPercentage());
		if (GetPercentage() >= 1.0f) m_side3And4 = true;
	}
	if (GetPercentage() >= 1.0f)
	{
		m_percent = 0.0f;
		m_timer = 0;
	}
	return false;
}

void Spaceship::Draw(Core::Graphics & graphics, Spaceship& ship)
{
	DrawShip(graphics, ship);
	DrawDiamond(graphics, ship);
	DrawEnemy(graphics, ship);
	DrawEnemyPath(graphics, ship);
}

void Spaceship::DrawLine(Core::Graphics & graphics, const Vec2 & p1, const Vec2 & p2)
{
	graphics.DrawLine(p1.xy[0], p1.xy[1], p2.xy[0], p2.xy[1]);
}

void Spaceship::DrawShip(Core::Graphics & graphics, Spaceship & ship)
{
	graphics.SetColor(RGB(0, 255, 255));
	for (int i = 0; i < 10; ++i)
	{
		Vec2 point1 = ship.m_shipshape[i] + ship.m_position;
		Vec2 point2 = ship.m_shipshape[i + 1] + ship.m_position;
		ship.DrawLine(graphics, point1, point2);
	}
	graphics.SetColor(RGB(255, 0, 0));
	ship.DrawLine(graphics, m_turret[0], m_turret[1]);
}

void Spaceship::InitializePoints()
{
	m_shipshape[0] = Vec2{ -10,0 };
	m_shipshape[1] = Vec2{ 0,-15 };
	m_shipshape[2] = Vec2{ 0,-15 };
	m_shipshape[3] = Vec2{ 10,0 };
	m_shipshape[4] = Vec2{ 10,0 };
	m_shipshape[5] = Vec2{ 0,15 };
	m_shipshape[6] = Vec2{ 0,15 };
	m_shipshape[7] = Vec2{ -10,0 };
	m_shipshape[8] = Vec2{ -15,15 };
	m_shipshape[9] = Vec2{ 15, 15 };
	m_shipshape[10] = m_shipshape[4];
}

void Spaceship::InitializeEnemy()
{
	m_enemyposition = m_enemypath[0];
	m_enemyshape[0] = Vec2{ 10, 0 };
	m_enemyshape[1] = Vec2{ 8, -6 };
	m_enemyshape[2] = Vec2{ 6, -12 };
	m_enemyshape[3] = Vec2{ 4, -18 };
	m_enemyshape[4] = Vec2{ -4, -18 };
	m_enemyshape[5] = Vec2{ -6, -12 };
	m_enemyshape[6] = Vec2{ -8, -6 };
	m_enemyshape[7] = Vec2{ -10, 0 };
	m_enemyshape[8] = Vec2{ 10, 0 };
	
}

void Spaceship::InitializeEnemyPoints()
{
	m_enemypath[0] = Vec2{ 600, 100 };
	m_enemypath[1] = Vec2{ 300, 100 };
	m_enemypath[2] = Vec2{ 300, 300 };
	m_enemypath[3] = Vec2{ 600, 300 };
	m_enemypath[4] = Vec2{ 600, 100 };
}


void Spaceship::DrawDiamond(Core::Graphics & graphics, Spaceship & ship)
{
	m_diamondshape[0] = Vec2{-GameManager::screenWidth / 2, 0};
	//m_diamondshape[1] = Vec2{0, GameManager::screenHeight/2};
	m_diamondshape[1] = Vec2{ GameManager::screenWidth / 2, 0 };

	graphics.SetColor(RGB(255, 0, 255));
	Vec2 point1 = ship.m_diamondshape[0] + ship.m_diamondposition;
	Vec2 point2 = ship.m_diamondshape[1] + ship.m_diamondposition;
	ship.DrawLine(graphics, point1, point2);
}

void Spaceship::DrawEnemy(Core::Graphics & graphics, Spaceship & ship)
{
	graphics.SetColor(RGB(165, 65, 65));
	for (int i = 0; i < 8; ++i)
	{
		Vec2 point1 = ship.m_enemyshape[i] + ship.m_enemyposition;
		Vec2 point2 = ship.m_enemyshape[i + 1] + ship.m_enemyposition;
		ship.DrawLine(graphics, point1, point2);
	}
}

void Spaceship::DrawEnemyPath(Core::Graphics & graphics, Spaceship & ship)
{
	graphics.SetColor(RGB(165, 0, 0));

	for (int i = 0; i < 1; ++i)
	{
		Vec2 point1 = ship.m_enemypath[i] + ship.m_enemyposition;
		Vec2 point2 = ship.m_enemypath[i + 1] + ship.m_enemyposition;
	}
}

float Spaceship::GetPercentage()
{
	float pointReached = (m_enemypath[1] - m_enemypath[0]).Length() / m_enemyspeed;
	m_percent = m_timer / pointReached;
	return m_percent;
}

bool Spaceship::CheckWrap()
{
	if (m_wrap)
	{
		if (m_position.xy[0] >= GameManager::screenWidth) {
			m_position = Vec2{0, m_position.xy[1]};
		}
		else if (m_position.xy[0] <= 0)
		{
			m_position = Vec2{ (float)GameManager::screenWidth, m_position.xy[1] };
		}
		else if (m_position.xy[1] <= 0)
		{
			m_position = Vec2{ m_position.xy[0], (float)GameManager::screenHeight };
		}
		else if (m_position.xy[1] >= GameManager::screenHeight)
		{
			m_position = Vec2{ m_position.xy[0], 0 };
		}
		return true;
	}
	return false;
}

bool Spaceship::CheckBounce()
{
	if (m_bounce)
	{
		if (m_position.xy[0] >= GameManager::screenWidth) 
		{
			m_position = Vec2{ (float)GameManager::screenWidth, m_position.xy[1] };
		}
		if (m_position.xy[0] <= 0)
		{
			m_position = Vec2{ 0, m_position.xy[1] };
		}
		if (m_position.xy[1] <= 0)
		{
			m_position = Vec2{ m_position.xy[0], 0 };
		}
		if (m_position.xy[1] >= GameManager::screenHeight)
		{
			m_position = Vec2{ m_position.xy[0], (float)GameManager::screenHeight };
		}
		return true;
	}
	return false;
}

bool Spaceship::CheckACollision()
{
	Vec2 wall = m_diamondshape[0] - m_diamondshape[1];
	Vec2 normVec = wall.PerpCW().Normalize();
	Vec2 distanceVec =m_diamondshape[0] - m_position;
	Vec2 distanceShip = distanceVec.Proj(normVec);
	float distance = distanceShip.Length();
	if (distance <= 1.0f)
	{
		m_position = m_position + (normVec * 2.0f * (-m_velocity.Dot(normVec))); 
		return true;
	}
	return false;
}

void Spaceship::ChangeSettings()
{
	if (Core::Input::IsPressed(VK_NUMPAD1) && m_bounce && !m_wrap)
	{
		m_bounce = false;
		m_wrap = true;
	}
	else if (Core::Input::IsPressed(VK_NUMPAD2) && !m_bounce && m_wrap)
	{
		m_bounce = true;
		m_wrap = false;
	}
}