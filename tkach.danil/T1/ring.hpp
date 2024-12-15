#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace tkach
{
  class Ring: public Shape
  {
  public:
    Ring(const point_t& center, double outer_radius, double inner_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(const point_t& point_to_move) override;
    void scale(double multiplier) override;
  private:
    point_t center_;
    double outer_radius_;
    double inner_radius_;
  };
}

#endif
