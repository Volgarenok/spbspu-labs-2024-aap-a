#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "ellipse.hpp"

namespace sharifullina
{
  class Circle: public Ellipse
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#endif
