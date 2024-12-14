#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "baseTypes.hpp"

namespace shramko
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getRectangleFrame() const = 0;
    virtual void move(point_t s) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
  };
}

#endif
