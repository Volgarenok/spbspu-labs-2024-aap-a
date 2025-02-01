#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  struct ComplexQuad final: Shape
  {
    ComplexQuad();
    ComplexQuad(point_t A, point_t B, point_t C, point_t D);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ComplexQuad *clone() const override;
  private:
    point_t points[4];

    point_t getA() const;
    point_t getB() const;
    point_t getC() const;
    point_t getD() const;
    point_t getCenterComplexQuad() const;
  };

  void createCQs(point_t p1, point_t p2, ComplexQuad &cq1, ComplexQuad &cq2, ComplexQuad &cq3, ComplexQuad &cq4);
}
#endif
