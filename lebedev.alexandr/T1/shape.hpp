#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"

namespace lebedev
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
  void deleteShapePtr(Shape** shps, size_t count);
}
#endif
