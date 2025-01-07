#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Concave final: Shape
  {
  public:
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t p1_, p2_, p3_, p4_;
    double getAreaOfComponent(point_t p1, point_t p2, point_t p3) const;
  };
}
#endif
