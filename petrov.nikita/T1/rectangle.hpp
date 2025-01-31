#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace petrov
{
  struct Rectangle final: Shape
  {
  public:
    Rectangle(const point_t & p1, const point_t & p2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const override;
  private:
    point_t p1_, p2_;
  };
}
#endif
