#pragma once
#include <iostream>
#include <math.h>
#include <ctime>
#include <string> 
#include <ostream>
#include <vector>
#include<list>

float const kEps = 1e-5f;
float const pi = 3.14159265358979323846f;
bool belong(float a, float b, float c);

bool EqualWithEps(float v1, float v2);

class Point2D
{
public:
  Point2D(float x, float y) :m_x(x), m_y(y) {};
  Point2D() = default;
  Point2D(Point2D const & obj): m_x(obj.m_x), m_y(obj.m_y) {}; // конструктор копирования
  void SetX(float x);
  void SetY(float y);
  float GetX() const;
  float GetY() const;
  void AddX(float x);
  void AddY(float y);
  bool operator == (Point2D const & obj) const;
  Point2D & operator = (Point2D const & obj);

  ~Point2D()=default;
private:
	
  float m_x = 0.0f, m_y = 0.0f;
};
  std::ostream & operator << (std::ostream & os, Point2D const & obj);


  class ExceptionDivisionByZero : public std::exception {};