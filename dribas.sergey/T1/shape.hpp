#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace dribas
{
  class Shape
  {
    virtual double getArea() const;
    virtual Rectange_t getFrameRect() const;
    virtual void move(Point_t point);
    virtual void move(double x, double y);
    virtual void scale(double ratio);
  };

}
#endif
