#include"Space.h"
#include"Logger.h"

Space::Space(float x, float y) : Box2D(Point2D(0, 0), Point2D(x, y)) { CLogger::GetLogger()->Log("Gun created"); };
Space::Space(Point2D const &  a, Point2D const &  b) : Box2D(a, b) { CLogger::GetLogger()->Log("Gun created"); };
Space::Space(Box2D  const & b) : Box2D(b) {};
