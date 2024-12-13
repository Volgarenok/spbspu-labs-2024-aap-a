#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace tkach
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double add_to_x, double add_to_y) = 0;
    virtual void move(point_t point_to_move) = 0;
    virtual void scale(double multiplier) = 0;
    virtual ~Shape() = default;
  };
}

#endif