#pragma once
#include "Figures.h"
#include"Bullet.h"

class Obstacle : public GameEntity
{
public:
  Obstacle() = default;
  Obstacle(Box2D const &  body);
  Obstacle(Point2D const &  a,Point2D const &  b);
  Obstacle(float x, float y, float x1, float y1);

  ~Obstacle() = default;
};

 