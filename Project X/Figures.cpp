#include "Figures.h"

Box2D::Box2D(float x, float y, float x1, float y1) 
{	
  m_lCorner = Point2D(x, y);
  m_rCorner = Point2D(x1, y1);
  Correctness();
}
Box2D::Box2D(Point2D const &  lCorner,Point2D const &  rCorner)
{
  m_lCorner = lCorner;
  m_rCorner = rCorner;
  Correctness();
}
Box2D::Box2D(Box2D const & b)
{
  *this=b;
  Correctness();
}
Box2D::Box2D(float x, float y) 
{
  m_lCorner=Point2D(0.0f, 0.0f);
  m_rCorner = Point2D(x, y);
  Correctness();
};
Box2D::Box2D(Box2D && obj)
{
  std::swap(m_lCorner,obj.GetLCorner());
  std::swap(m_rCorner, obj.GetRCorner());
}

void Box2D::Correctness()  
{
  if ((m_lCorner.GetX() == m_rCorner.GetX())||(m_lCorner.GetX() > m_rCorner.GetX())) throw std::invalid_argument("X coordinate of lefr corner must be smaller than the X coordinate of right corner");
  if ((m_lCorner.GetY() == m_rCorner.GetY())||(m_lCorner.GetY() > m_rCorner.GetY())) throw std::invalid_argument("Y coordinate of lefr corner must be smaller than the Y coordinate of right corner");
}

double Box2D::GetHeight() const
{
  return (m_rCorner.GetX() - m_lCorner.GetX());
};
double Box2D::GetWidth() const
{
  return (m_rCorner.GetX() - m_lCorner.GetX());
};

void Box2D::Move(float dx, float dy)
{
  m_lCorner.AddX(dx);
  m_lCorner.AddY(dy);
  m_rCorner.AddX(dx);
  m_rCorner.AddY(dy);
}

void Box2D::SetLcorner(float x, float y)
{
  m_lCorner = { x, y };
  Correctness();
}
void Box2D::SetRcorner(float x, float y)
{
  m_rCorner = { x, y };
  Correctness();
}

Point2D  Box2D::GetLCorner() const &
{
  return m_lCorner;
}
Point2D  Box2D::GetRCorner() const & 
{
  return m_rCorner;
}
Point2D   Box2D::GetCenter() const &
{
  return Point2D((GetRCorner().GetX()+ GetLCorner().GetX())/2, (GetRCorner().GetY() + GetLCorner().GetY()) / 2);
}

bool Box2D::Intersection(Box2D const & box) const
{
  if (m_rCorner.GetX() < box.GetLCorner().GetX()) return false;
  if (m_lCorner.GetX() > box.GetRCorner().GetX()) return false;
  if (m_rCorner.GetY() < box.GetLCorner().GetY()) return false;
  if (m_lCorner.GetY() > box.GetRCorner().GetY()) return false;
    return true; 
  box.GetLCorner().GetX();
};

Box2D & Box2D::operator = (Box2D const & obj)
{
  m_lCorner=obj.GetLCorner();
  m_rCorner=obj.GetRCorner();
  return *this;
}
bool Box2D::operator == (Box2D const & obj) const
{
  return (m_lCorner==obj.GetLCorner())&&(m_rCorner==obj.GetRCorner());
}
Box2D & Box2D::operator = (Box2D && obj)
{
  std::swap(m_lCorner, obj.GetLCorner());
  std::swap(m_rCorner, obj.GetRCorner());
  return *this;
}

///////////////////////////////////////////ЛУЧ

Ray2D::Ray2D(float x0, float y0, float x, float y) :m_origin(x0, y0), m_direction(x , y ) {};

Ray2D::Ray2D(Ray2D const & b)
{
  *this=b;
}

Ray2D::Ray2D(float x, float y) :m_origin(0.0f, 0.0f), m_direction(x , y ) {};

Ray2D::Ray2D(Point2D const &  origin, Point2D const &  direction)
{
  m_origin=origin;
  m_direction=direction;
};
Point2D  Ray2D::GetOrigin() const & 
{
  return m_origin;
}

Point2D  Ray2D::  GetDirection() const &
{
  return m_direction;
}

float Ray2D::GetK() const
{
  return m_k;
}

bool Ray2D::Intersection(Box2D const & b) const
{
  if (GetDirection().GetX() > 0)
  {
    if (b.GetRCorner().GetX() <GetOrigin().GetY())
      return false;
  }
  if (GetDirection().GetX() < 0)
  {
    if (b.GetLCorner().GetX() > GetOrigin().GetY())
      return false;
  }
  if (GetDirection().GetY() > 0)
  {
    if (b.GetRCorner().GetY() < GetOrigin().GetY())
      return false;
  }
  if (GetDirection().GetY() < 0)
  {
    if (b.GetLCorner().GetY() > GetOrigin().GetY())
      return false;
  }

  if (GetDirection().GetX() == 0)
  {
    if (belong(b.GetLCorner().GetX(), GetOrigin().GetY(), b.GetRCorner().GetY()))
      {
            return true;
      }
  }
  if (GetDirection().GetY() == 0)
  {
    if (belong(b.GetLCorner().GetY(), GetOrigin().GetY(), b.GetRCorner().GetY()))
    {
          return true;
    }
  }

  float x0, y0, x1, y1;
  y0 = (b.GetLCorner().GetX() - GetOrigin().GetY()) * GetK()+GetOrigin().GetY();
  y1 = (b.GetRCorner().GetX() - GetOrigin().GetY()) * GetK()+GetOrigin().GetY();
  x0 = (b.GetLCorner().GetY() - GetOrigin().GetY()) / GetK()+GetOrigin().GetY();
  x1 = (b.GetRCorner().GetY() - GetOrigin().GetY()) / GetK()+GetOrigin().GetY();
  return belong(b.GetLCorner().GetX(), x0, b.GetRCorner().GetX()) || belong(b.GetLCorner().GetY(), y0, b.GetRCorner().GetY())
    || belong(b.GetLCorner().GetX(), x1, b.GetRCorner().GetX()) || belong(b.GetLCorner().GetY(), y1, b.GetRCorner().GetY());
}

Ray2D & Ray2D::operator = (Ray2D const & obj)
{
  m_origin=obj.GetOrigin();
  m_direction=obj.GetDirection();
  return *this;
}
bool Ray2D::operator == (Ray2D const & obj) const
{
  return (m_origin == obj.GetOrigin()) && (m_direction == obj.GetDirection());
}
Ray2D & Ray2D::operator = (Ray2D && obj)
{
  std::swap(m_origin, obj.GetOrigin());
  std::swap(m_direction, obj.GetDirection());
  return *this;
}