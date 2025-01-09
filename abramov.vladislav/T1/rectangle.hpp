#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "complexquad.hpp"

namespace abramov
{
  struct Rectangle final: Shape
  {
    Rectangle(point_t p1, point_t p2);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Rectangle *clone() const override;
  private:
    ComplexQuad cmplxqds[4];
  };
}
#endif
