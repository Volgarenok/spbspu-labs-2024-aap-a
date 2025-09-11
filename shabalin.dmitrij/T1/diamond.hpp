#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace shabalin
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t, point_t, point_t);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t);
    virtual void move(double, double);
    virtual void scaleShape(double);
    virtual ~Diamond() = default;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif
