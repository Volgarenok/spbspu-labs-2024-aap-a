#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  struct ComplexQuad final: Shape
  {
    ComplexQuad(point_t A, point_t B, point_t C, point_t D);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    point_t getA() const;
    point_t getB() const;
    point_t getC() const;
    point_t getD() const;
  private:
    point_t A_;
    point_t B_;
    point_t C_;
    point_t D_;

    point_t getCenterComplexQuad() const;
  };

  void createCQs(point_t p1, point_t p2, ComplexQuad &cq1, ComplexQuad &cq2, ComplexQuad &cq3, ComplexQuad &cq4);
}
#endif
