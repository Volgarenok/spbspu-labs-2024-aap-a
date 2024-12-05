#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  struct ComplexQuad: Shape
  {
    ComplexQuad(point_t A, point_t B, point_t C, point_t D);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t A;
    point_t B;
    point_t C;
    point_t D;
  };
}
#endif
