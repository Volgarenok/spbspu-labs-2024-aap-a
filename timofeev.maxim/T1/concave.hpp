#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include "shapes_tools.hpp"
#include <iostream>

namespace timofeev {
  class Concave final: public Shape
  {
  public:
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t new_pos) override;
    void move(double move_x, double move_y) override;
    void scale(double factor) override;

  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif
