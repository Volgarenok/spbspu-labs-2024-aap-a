#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle
{
public:
  Triangle() : x1_{}, x2_{}, x3_{} {}
  Triangle(point_t x1, point_t x2, point_t x3): x1_(x1), x2_(x2), x3_(x3)
  {}
  void move(double x, double y);
  void move(point_t t);
  double getArea();
  rectangle_t getFrameRect();
  void scale(point_t t, double k);
  ~Triangle(){}
private:
  point_t x1_;
  point_t x2_;
  point_t x3_;
};

#endif
