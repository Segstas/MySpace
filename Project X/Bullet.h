#pragma once
#include"GameEntity.h"
#include<ctime>
#include"Gun.h"
#include"Alien.h"
#include"Obstacle.h"
#include<vector>

class Alien;
class Gun;
class Obstacle;

class Bullet : public GameEntity
{
public:
  Bullet()=default;
  Bullet(Box2D const & b,Point2D const & dir);
  Bullet(float x, float y, float x1, float y1,float x2,float y2);
  Bullet(Point2D const &  lCorner,Point2D const &  rCorner,Point2D const & direction);
  
  bool Hit(std::list<Gun> & obj);
  bool Hit(std::list<Alien> & obj);
  bool Hit(std::list<Obstacle> & obj);
  float GetSpeed() const;
 
  ~Bullet() = default;
private:
  float const  m_standartHeigth=1, m_standartWidth=1;
  float m_timeOfShot=clock();
  float const m_speed=1;//единиц в секунду
};
