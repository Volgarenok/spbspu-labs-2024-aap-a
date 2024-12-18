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
    virtual void move(guseynov::point_t pos) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
}

#endif
