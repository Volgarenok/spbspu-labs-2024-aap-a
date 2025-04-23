#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace balashov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double xPos, double yPos) = 0;
    virtual void scale(double coefficient) = 0;
    virtual ~Shape() = default;
  };
}
#endif
