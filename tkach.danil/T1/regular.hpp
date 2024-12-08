#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace tkach
{
  class Regular: public Shape
  {
  public:
    Regular(point_t first_point, point_t second_point, point_t third_point);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept;
    void move(double add_to_x, double add_to_y) noexcept override;
    void move(point_t point_to_move) noexcept override;
    void scale(double multiplier) noexcept override;
  private:
    point_t first_point_;
    point_t second_point_;
    point_t third_point_;
  };
}

#endif