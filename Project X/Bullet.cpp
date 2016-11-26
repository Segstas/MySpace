#include"Bullet.h"
#include "Logger.h"

Bullet::Bullet(float x, float y, float x1, float y1, float x2, float y2) :
	GameEntity(Box2D(x, y, x1, y1), Ray2D((x1 + x) / 2, (y1 + y) / 2, x2, y2), 100) {
	CLogger::GetLogger()->Log("Bullet created");
};

Bullet::Bullet(Box2D const & b, Point2D const & dir) : GameEntity(b, Ray2D(b.GetCenter(), dir), 100) { CLogger::GetLogger()->Log("Bullet created"); };


Bullet::Bullet(Point2D  const & lCorner, Point2D const &  rCorner, Point2D  const & direction) :
	GameEntity(Box2D(lCorner, rCorner), Ray2D(Point2D((rCorner.GetX() + lCorner.GetX()) / 2, (rCorner.GetY() + lCorner.GetY()) / 2), direction), 100) {
	CLogger::GetLogger()->Log("Bullet created");
};


float Bullet::GetSpeed() const
{
	return m_speed;
}
bool Bullet::Hit(std::list<Gun> & obj)
{
	for (auto it = obj.begin(); it != obj.end(); ++it)
	{
		if (GetBody().Intersection(it->GetBody()))
		{
			it->SetHealth(-GetDamage());
			return true;
		}
	}
	return false;
}
bool Bullet::Hit(std::list<Alien> & obj)
{
	for (auto it = obj.begin(); it != obj.end(); ++it)
		if (GetBody().Intersection(it->GetBody()))
		{
			it->SetHealth(-GetDamage());
			return true;
		}
	return false;
}
bool Bullet::Hit(std::list<Obstacle> & obj)
{
	for (auto it = obj.begin(); it != obj.end(); ++it)
		if (GetBody().Intersection(it->GetBody()))
		{
			it->SetHealth(-GetDamage());
			return true;
		}
	return false;
}