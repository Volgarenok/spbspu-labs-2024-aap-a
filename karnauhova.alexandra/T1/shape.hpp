#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape{
public:
  virtual ~Shape() = default;
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(double x, double y) = 0;
  virtual void move(point_t t) = 0;
  virtual void scale(point_t t, int k) = 0;
};
#endif
