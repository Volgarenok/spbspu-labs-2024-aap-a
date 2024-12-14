#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape {
public:
  virtual float getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(point_t p) = 0;
  virtual void move(float dx, float dy) = 0;
  virtual void scale(float k) = 0;
};

#endif
