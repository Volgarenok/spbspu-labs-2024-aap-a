#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace kiselev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t a) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    void scaleWithCheck(double k);
    virtual Shape* clone() const = 0;
  };
}
#endif
