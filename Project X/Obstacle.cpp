#include"Obstacle.h"



Obstacle::Obstacle(Box2D  const & body):GameEntity(body,1000) {};
Obstacle::Obstacle(Point2D const &  a, Point2D const &  b) : GameEntity(Box2D(a, b), 1000) {};
Obstacle::Obstacle(float x, float y, float x1, float y1) :GameEntity(Box2D(x, y, x1, y1), 1000) {};


