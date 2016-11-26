#include"Gun.h"
#include"Logger.h"



Gun::Gun(float x, float y, float x1, float y1) : GameEntity(Box2D(x, y, x1, y1), 100) { CLogger::GetLogger()->Log("Gun created"); };
Gun::Gun(Box2D const &  body) :GameEntity(body, 100) { CLogger::GetLogger()->Log("Gun created"); };



