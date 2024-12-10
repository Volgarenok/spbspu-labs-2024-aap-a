#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace brevnov
{
  class Shape 
  {
    virtual double getArea() = 0;
    virtual rectangle getFrameRect() = 0;
    virtual void move(point_t new_centre) = 0;
    virtual void scale(double n) = 0;
    virtual ~Shape() = default;
  };
}
#endif
