#pragma once
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
  point_t lb;
  point_t rt;
public:
  Rectangle(point_t a, point_t b);
  double getArea();
  rectangle_t getFrameRect();
  void move(point_t pos);
  void move(double x, double y);
  void scale(double scale);
};