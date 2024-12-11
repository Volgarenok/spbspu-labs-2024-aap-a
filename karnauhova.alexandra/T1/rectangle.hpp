#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t x4, point_t x2): x2_(x2), x4_(x4)
  {}
  void move(double x, double y);
  void move(point_t t);
  double getArea();
  rectangle_t getFrameRect();
  void scale(point_t t, double k);
  ~Rectangle(){}
private:
  point_t x2_;
  point_t x4_;
};

#endif
