#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace petrov
{
  struct Triangle final: Shape
  {
  public:
    Triangle(const point_t & p1, const point_t & p2, const point_t & p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
  private:
    point_t p1_, p2_, p3_;
  };
}
#endif
