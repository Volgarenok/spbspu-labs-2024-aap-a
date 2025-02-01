#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace savintsev
{
  class Complexquad final: public Shape
  {
  public:
    Complexquad(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double x, double y) override;
    Shape * clone() const override;
    void unsafeScale(double k) noexcept override;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif
