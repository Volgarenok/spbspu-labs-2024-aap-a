#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace maslov
{
  struct Shape
  {
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t s) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k);
    virtual void scaleWithoutCheck(double k) = 0;
    virtual Shape * clone() const = 0;
  };
}

#endif
