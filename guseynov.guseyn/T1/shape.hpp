#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace guseynov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pos) const = 0;
    virtual void move(double x, double y) const = 0;
    virtual void scale(double k) const = 0;
    virtual ~Shape() = default;
  };
}

#endif
