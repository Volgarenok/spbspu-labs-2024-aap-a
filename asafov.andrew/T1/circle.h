#pragma once
#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
  point_t center;
  double radius;
public:
  Circle(point_t pos, double _rad);
  double getArea();
  rectangle_t getFrameRect();
  void move(point_t pos);
  void move(double x, double y);
  void scale(double scale);
};
