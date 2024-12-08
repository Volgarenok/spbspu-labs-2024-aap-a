#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace dribas
{
  class Shape
  {
    virtual double getArea() const = 0;
    virtual Rectangle_t getFrameRect() const = 0;
    virtual void move(Point_t point) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double ratio) = 0;
  };

}
#endif
