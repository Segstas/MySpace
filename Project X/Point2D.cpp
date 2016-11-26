#include "Point2D.h"

bool belong(float a, float b, float c)
{
  return  ((((b >= a)) && (b <= c))
    || ((b >= c) && (b <= a)));

}
bool EqualWithEps(float v1, float v2)
{
  return fabs(v1 - v2) < kEps;
}

void Point2D:: SetX(float x) 
{
  m_x = x;
};
void Point2D::SetY(float y)
{
  m_y = y;
}

float Point2D::GetX() const
{
  return m_x;
}
float  Point2D::GetY() const
{
  return m_y;
}
void Point2D::Point2D::AddX(float x)
{
  m_x += x;
}
void Point2D::AddY(float y)
{
  m_y += y;
}

bool  Point2D::operator == (Point2D const & obj) const
{
  return EqualWithEps(m_x, obj.m_x) && EqualWithEps(m_y, obj.m_y);
}
Point2D &  Point2D::operator = (Point2D const & obj)
{
  if (this == &obj) return *this;
  m_x = obj.m_x;
  m_y = obj.m_y;
  return *this;
}

std::ostream & operator << (std::ostream & os, Point2D const & obj)
{
  os << "Point2D {" << obj.GetX() << ", " << obj.GetY() << "}";
  return os;
}