#pragma once
#include "Figures.h"


class Space : public Box2D
{
public:
  Space() = default;
  Space(float x,float y);
  Space(Point2D const & a, Point2D const & b);
  Space(Box2D const &  b);

  ~Space() = default;
};

