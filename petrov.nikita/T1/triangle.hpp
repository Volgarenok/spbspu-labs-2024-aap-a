#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Triangle: Shape
  {
  public:
    Triangle(point_t p1, point_t p2, point_t p3);
    double getArea() override;
    point_t * getFrameRect() override;
    void move(point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t p1_, p2_, p3_;
    rectangle_t frame_rect_;
    point_t frame_points_[3];
  };
}
#endif
