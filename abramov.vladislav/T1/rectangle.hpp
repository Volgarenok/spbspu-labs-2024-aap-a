#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "complexquad.hpp"

namespace abramov
{
  struct Rectangle final: Shape
  {
    Rectangle(point_t p1, point_t p2);
    Rectangle(ComplexQuad cq1, ComplexQuad cq2, ComplexQuad cq3, ComplexQuad cq4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    ComplexQuad getCQ1() const;
    ComplexQuad getCQ2() const;
    ComplexQuad getCQ3() const;
    ComplexQuad getCQ4() const;
  private:
    ComplexQuad cmplxqd1_;
    ComplexQuad cmplxqd2_;
    ComplexQuad cmplxqd3_;
    ComplexQuad cmplxqd4_;
  };
}
#endif
