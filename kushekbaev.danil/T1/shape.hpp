#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace kushekbaev
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t Z) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double V) = 0;
    virtual ~Shape() = default;
  };
}

#endif
