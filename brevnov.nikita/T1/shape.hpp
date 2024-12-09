#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
class Shape 
{
  virtual double getArea();
  virtual rectangle getFrameRect();
  virtual void move(point_t k);
  virtual void scale(double n);
};
#endif
