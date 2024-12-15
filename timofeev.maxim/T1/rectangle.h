#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include "base-types.hpp"

namespace timofeev
{
  class Rectangle : public Shape {
  public:
    Rectangle(double ldx, double ldy, double rux, double ruy);
    double get_area() const override;
    rectangle_t get_frame_rect() const override;
    void move(point_t new_pos) override;
    void move(double move_x, double move_y) override;
    void scale(double factor) override;

  private:
    point_t ld_;
    point_t ru_;
  };
}
#endif
