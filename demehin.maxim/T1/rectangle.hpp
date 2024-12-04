#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base_types.hpp"
#include "shape.hpp"

namespace demehin
{
  class Rectangle: public Shape
  {
  public:
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
    point_t lb_;
    point_t rt_;
  };
}

#endif
