#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>
#include "base-types.hpp"

namespace finaev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t a) = 0;
    virtual void move(double sx, double sy) = 0;
    virtual void scale(double k) = 0;
  };
  void deleteShapes(Shape** shapes, const size_t size);
}

#endif
