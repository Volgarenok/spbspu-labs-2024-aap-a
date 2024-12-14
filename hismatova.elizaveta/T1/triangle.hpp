#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace hismatova
{
  struct triangle : public shape
  {
    triangle(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void move(point_t point) override;
    void scale(double index) override;
    point_t get_center() const;
  private:
    point_t p1_, p2_, p3_;
  };
}

#endif
