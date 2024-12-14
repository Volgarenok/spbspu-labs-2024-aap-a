#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace rychkov
{
  class Shape
  {
  public:
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(point_t destination) noexcept = 0;
    virtual void move(double deltaX, double deltaY) noexcept = 0;
    virtual void scale(double coef) = 0;
  };
}

#endif
