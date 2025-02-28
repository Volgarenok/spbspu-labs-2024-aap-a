#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace asafov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pos) = 0;
    virtual void move(double x, double y) = 0;
    void scale(double scale);
    virtual ~Shape() = default;
    virtual void unsafeScale(double scale) = 0;
  };
}
#endif
