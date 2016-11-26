#include"GameEntity.h"


GameEntity::GameEntity(Box2D body, float health) :m_body(body), m_health(health)
{
  if(m_health <=0)  throw std::invalid_argument("Healt must be greater than 0");
};
GameEntity::GameEntity(Box2D body, Ray2D dir,float damage):m_body(body),m_direction(dir),m_health(1),m_damage(damage)
{
  if (m_damage <= 0)  throw std::invalid_argument("Damage must be greater than 0");
};

Box2D GameEntity::GetBody() const &
{
  return m_body;
}
Ray2D GameEntity::GetRay() const &
{
  return m_direction;
}
float GameEntity::GetHealth() const
{
  return m_health;
}
void GameEntity::SetHealth(float a) 
{
  m_health+=a;
}
float GameEntity::GetDamage() const
{
  return m_damage;
}
