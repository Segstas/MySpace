#include"Alien.h"
#include"Logger.h"

Alien::Alien(float x, float y, float x1, float y1) :GameEntity(Box2D(x, y, x1, y1), 100) { CLogger::GetLogger()->Log("Alien created"); };
Alien::Alien(Box2D const &  body) : GameEntity(body, 100) { CLogger::GetLogger()->Log("Alien created"); };


