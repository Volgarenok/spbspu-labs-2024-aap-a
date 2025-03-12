#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "complexquad.hpp"

namespace abramov
{
  struct Rectangle final: Shape
  {
    Rectangle(const point_t &p1, const point_t &p2);
    ~Rectangle();
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Rectangle *clone() const override;
  private:
    ComplexQuad *cmplxqds;
  };
}
#endif
