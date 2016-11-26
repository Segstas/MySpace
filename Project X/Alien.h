#pragma once
#include"GameEntity.h"


class Alien : public GameEntity
{
public:
  Alien() = default;
  Alien(float x, float y, float x1, float y1);
  Alien(Box2D const & body);

  ~Alien() = default;
private:
  float m_speed;
  float rate = 1; //скорострельность пуль/сек
};
