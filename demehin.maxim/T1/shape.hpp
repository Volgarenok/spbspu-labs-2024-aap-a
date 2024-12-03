#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base_types.hpp"

namespace demehin
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual demehin::rectangle_t getFrameRect() const = 0;
    virtual void move() = 0;
    virtual void scale() = 0;
  };
}

#endif
