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
    ComplexQuad(const point_t &A, const point_t &B, const point_t &C, const point_t &D);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ComplexQuad *clone() const override;
    point_t getA() const;
    point_t getB() const;
    point_t getC() const;
    point_t getD() const;
  private:
    point_t points[4];

    point_t getCenterComplexQuad() const;
  };

  void createCQs(const point_t &p1, const point_t &p2, ComplexQuad &cq1, ComplexQuad &cq2, ComplexQuad &cq3, ComplexQuad &cq4);
}
#endif
