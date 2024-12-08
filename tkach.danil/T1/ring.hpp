#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace tkach
{
  class Ring: public Shape
  {
  public:
    Ring(point_t center, double outer_radius, double inner_radius);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept;
    void move(double add_to_x, double add_to_y) noexcept override;
    void move(point_t point_to_move) noexcept override;
    void scale(double multiplier) noexcept override;
  private:
    point_t center_;
    double outer_radius_;
    double inner_radius_;
  };
}

#endif