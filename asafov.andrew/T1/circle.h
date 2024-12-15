#pragma once
#include "shape.hpp"

class Circle : public Shape
{
  point_t center;
  double radius;
public:
  Circle(point_t pos, double _rad);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t pos);
  void move(double x, double y);
  void scale(point_t pos, double scale);
};
