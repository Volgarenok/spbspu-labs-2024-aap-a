#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.h"

namespace timofeev
{
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double get_area() const = 0;
    virtual rectangle_t get_frame_rect() const = 0;
    virtual void move(point_t new_pos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double factor) = 0;
  };
}
#endif
