#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace hismatova
{
  struct shape
  {
    virtual ~shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double x, double y) = 0;
    virtual void move(point_t point) = 0;
    virtual void scale(double index) = 0;
  };
}

#endif
