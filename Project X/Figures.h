#pragma once
#include "Point2D.h"
 

class Box2D 
{
public:
  Box2D(float x, float y, float x1, float y1);
  Box2D()=default;
  Box2D(Box2D const & b);
  Box2D(float x, float y);
  Box2D(Point2D const &  lCorner, Point2D const &  rCorner);
  Box2D(Box2D && obj);
  
  void Correctness();
  double GetHeight() const;// возвращает длину
  double GetWidth() const;//возвращает ширину
  void Move(float dx, float dy);//переещение объекта на плоскости

  void SetLcorner(float x, float y);//изменить координаты левого угла
  void SetRcorner(float x, float y);//изменить координаты правого угла

  Point2D  GetLCorner()const &;
  Point2D  GetRCorner()const &;
  Point2D  GetCenter()const &;
	
  bool Intersection(Box2D const & obj) const;//проверка на пересечение
  Box2D & operator = (Box2D const & obj);
  Box2D & operator = (Box2D && obj);
  bool operator == (Box2D const & obj) const;

  ~Box2D()=default;
private:
  Point2D m_lCorner, m_rCorner;

};

class Ray2D 
{
public:
  Ray2D(float x0, float y0, float x, float y) ;
  Ray2D()=default;
  Ray2D(Ray2D const & b);
  Ray2D(Point2D  const & origin,Point2D  const & direction);
  Ray2D(float x, float y);
  Point2D  GetOrigin() const & ;
  Point2D   GetDirection() const &;
  float GetK() const;
  bool Intersection(Box2D const & obj) const;

  Ray2D & operator = (Ray2D const & obj);
  Ray2D & operator = (Ray2D && obj);
  bool operator == (Ray2D const & obj) const;

  ~Ray2D() = default;
private:
  Point2D m_origin, m_direction;
  float m_k = (m_direction.GetY()) / (m_direction.GetX());
};

