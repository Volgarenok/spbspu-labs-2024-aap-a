#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace tkach
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double add_to_x, double add_to_y) = 0;
    virtual void move(const point_t& point_to_move) = 0;
    virtual Shape* clone() const = 0;
    void scale(double multiplier);
    virtual void doUnsafeScale(double multiplier) = 0;
  };
}

#endif
