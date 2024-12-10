#ifndef RECRANGLE_HPP
#define RECRANGLE_HPP

#include "shape.hpp"

namespace tkach
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t left_bot_point, point_t right_top_point);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y) override;
    void move(point_t point_to_move) override;
    void scale(double multiplier) override;
  private:
    point_t left_bot_point_;
    point_t right_top_point_;
  };
}

#endif
