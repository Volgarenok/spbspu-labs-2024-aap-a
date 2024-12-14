#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "baseTypes.hpp"
#include "base.hpp"

namespace shramko
{
  class Rectangle: Shape
  {
  public:
    double getArea() const override;
    rectangle_t getRectangleFrame() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
    point_t leftBottom_;
    point_t rightTop_;
  };
}

#endif
