#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace timofeev
{
  class Rectangle : public Shape {
  public:
    Rectangle(double ldx, double ldy, double rux, double ruy);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t new_pos) override;
    void move(double move_x, double move_y) override;
    void scale(double factor) override;

  private:
    point_t ld_;
    point_t ru_;
  };
}
#endif
