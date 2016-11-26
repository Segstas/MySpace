#pragma once
#include"Figures.h"

class GameEntity
{
public:
  GameEntity()=default;
  GameEntity(Box2D body,float health);
  GameEntity(Box2D body,Ray2D dir,float damage);

  bool Hit(GameEntity & g);// проверка на попадание пули
  Box2D GetBody() const &;
  Ray2D GetRay() const &;
  float GetHealth() const;
  float GetDamage() const;
  void SetHealth(float a);

  virtual ~GameEntity()=default;
private:
  Box2D  m_body;
  Ray2D m_direction;
  float m_health, m_damage;
};