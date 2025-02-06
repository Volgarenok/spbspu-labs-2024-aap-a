#ifndef RING_HPP
#define RING_HPP

#include "regular.hpp"
#include "base-types.hpp"

namespace tkach
{
  class Ring final: public Shape
  {
  public:
    Ring(const point_t& center, double outer_radius, double inner_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(const point_t& point_to_move) override;
    void doUnsafeScale(double multiplier) override;
    Shape* clone() const override;
  private:
    Regular in_reg_;
    Regular out_reg_;
    Regular getReg(size_t sides_amount, const point_t& center, double radius);
  };
}

#endif
