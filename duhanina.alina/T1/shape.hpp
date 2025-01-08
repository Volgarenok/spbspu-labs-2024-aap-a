#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace duhanina
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    void scaleCheck(double k);
  };
}

#endif