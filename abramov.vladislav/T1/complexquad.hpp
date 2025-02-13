#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace abramov
{
  struct ComplexQuad final: Shape
  {
    ComplexQuad(const point_t &a, const point_t &b, const point_t &c, const point_t &d);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ComplexQuad *clone() const override;
  private:
    point_t points[4];

    point_t getCenterComplexQuad() const;
  };

  ComplexQuad *createCQs(const point_t &p1, const point_t &p2);
}
#endif
