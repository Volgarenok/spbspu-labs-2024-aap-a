#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sveshnikov
{
  class Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p);
    virtual void move(double dx, double dy);
    virtual void scale(double k);
  };
}

#endif
