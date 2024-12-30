#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace shabalin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t, point_t);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t);
    virtual void move(double, double);
    virtual void scaleShape(double);
    virtual ~Rectangle() = default;
  private:
    point_t rightUp;
    point_t leftDown;
  };
}
#endif
