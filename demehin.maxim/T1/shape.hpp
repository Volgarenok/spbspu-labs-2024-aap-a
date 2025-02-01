#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace demehin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t s) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scaleUnsafely(double k) = 0;
    void scale(double k);
  };
}

#endif
