#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace dribas
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double x, double y) = 0;
    void scale(double ratio);
    virtual ~Shape() = default;
    virtual Shape* clone() const = 0;
    virtual void scaleSilent(double ratio) = 0;
  };
}
#endif
