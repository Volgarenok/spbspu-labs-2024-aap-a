#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Rectangle: Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() override;
    point_t getFrameRect() override;
    void move(point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t p1_, p2_, p3_, p4_;
    rectangle_t frame_rect_;
  };
}
#endif
