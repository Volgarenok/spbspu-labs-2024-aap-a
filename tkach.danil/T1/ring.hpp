#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"
#include "regular.hpp"

namespace tkach
{
  class Ring final: public Shape
  {
  public:
    Ring(const point_t& center, double outer_radius, double inner_radius);
    ~Ring() override;
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(const point_t& point_to_move) override;
    void scaleOneOfUniqueShapes(double multiplier) override;
  private:
    Regular* in_reg_;
    Regular* out_reg_;
  };
}

#endif
