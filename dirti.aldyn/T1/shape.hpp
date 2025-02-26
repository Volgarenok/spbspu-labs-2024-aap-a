#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <stdexcept>
#include "base-types.hpp"

namespace dirti
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double x, double y) = 0;
    virtual void unsafeScale(double koef) = 0;
    void scale(double koef);
    virtual ~Shape() = default;
  };
}
#endif