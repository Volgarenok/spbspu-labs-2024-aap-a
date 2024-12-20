#ifndef SHAPE_HPP
#include "base-types.hpp"
#define SHAPE_HPP
namespace evstyunichev
{
  struct Shape
  {
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(double, double) = 0;
    virtual void move(point_t) = 0;
    virtual void scale(double) = 0;
    virtual ~Shape() = default;
  };
}
#endif
