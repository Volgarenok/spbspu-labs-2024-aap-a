#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sveshnikov
{
  class Shape
  {
    double getArea();
    rectangle_t getFrameRect();
    virtual void move(point_t p);
    virtual void move(double dx, double dy);
    void scale(double k);
  };
}

#endif