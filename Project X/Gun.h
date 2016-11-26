#pragma once
#include"Figures.h"
#include "Bullet.h"


class Gun : public GameEntity
{
public:
  Gun()=default;
  Gun(float x,float y,float x1, float y1);
  Gun(Box2D  const &  body);


~Gun()=default;
private:
  bool m_fired=false;// true если пуля в полете
  float m_speed;
  float rate=1; //скорострельность пуль/сек
};