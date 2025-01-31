#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include "triangle.hpp"

namespace petrov
{
  struct Concave final: Shape
  {
  public:
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
  private:
    Triangle triangle_1_, triangle_2_, triangle_3_, triangle_4_;
    double getAreaOfComponent(point_t p1, point_t p2, point_t p3) const;
  };
}
#endif
