#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

namespace finaev
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t a) = 0;
    virtual void move(double sx, double sy) = 0;
    virtual void scale(size_t k) = 0;
    virtual ~Shape() = default;
  };
}
#endif 
