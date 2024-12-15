#pragma once
#include "shape.hpp"

class Rectangle : public Shape
{
  point_t lb;
  point_t rt;
public:
  Rectangle(point_t a, point_t b);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t pos);
  void move(double x, double y);
  void scale(point_t pos, double scale);
};