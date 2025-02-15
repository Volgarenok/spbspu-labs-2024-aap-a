#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace tkach
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& left_bot_point, const point_t& right_top_point);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double add_to_x, double add_to_y) override;
    void move(const point_t& point_to_move) override;
    void doUnsafeScale(double multiplier) override;
    Shape* clone() const override;
  private:
    point_t left_bot_point_;
    point_t right_top_point_;
  };
}

#endif
