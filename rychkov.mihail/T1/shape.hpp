#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace rychkov
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getArea() = 0;
    virtual void move(point_t destination) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual void scale(double coef) = 0;
  };
}

#endif
