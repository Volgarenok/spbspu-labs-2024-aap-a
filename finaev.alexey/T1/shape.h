#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include "base-types.h"

namespace finaev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t a) = 0;
    virtual void move(double sx, double sy) = 0;
    virtual void scale(double k) = 0;
  };
  void deleteShapes(finaev::Shape** shapes, size_t size);
}

#endif