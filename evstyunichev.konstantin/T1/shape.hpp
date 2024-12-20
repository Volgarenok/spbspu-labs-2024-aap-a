#ifndef SHAPE_HPP
#include "base-types.hpp"
#define SHAPE_HPP
namespace evstyunichev
{
  struct Shape
  {
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double, double);
    virtual void move(point_t);
    virtual void scale(double);
  };
}
#endif
