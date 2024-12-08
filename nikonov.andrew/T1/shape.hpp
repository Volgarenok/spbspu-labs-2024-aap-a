#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace nikonov
{
  struct Shape
  {
    virtual float getArea() const = 0;
    virtual nikonov::rectangle_t getFrameRect() const = 0;
    virtual void move(point_t a) = 0;
    virtual void move(float x, float y) = 0;
    virtual void scale(float k) = 0;
    virtual ~Shape() = default;
  };
}
#endif
