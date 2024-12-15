#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace finaev
{
  class Rectangle :public Shape
  {
  private:
    point_t leftDown;
    point_t rightUp;
  public:
    Rectangle(point_t l, point_t r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  };
}

#endif
