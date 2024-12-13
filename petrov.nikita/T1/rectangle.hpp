#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Rectangle: public Shape
  {
  public:
    Rectangle(double * massive);
    void getArea() override;
    void getFrameRect() override;
    void move(point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t p1_, p2_;
    rectangle_t frame_rect_;
  };
}
#endif