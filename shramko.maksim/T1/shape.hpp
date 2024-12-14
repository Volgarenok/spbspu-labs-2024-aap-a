#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "baseTypes.hpp"

namespace shramko
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual shramko::rectangle_t getRectangleFrame const = 0;
    virtual void move() = 0;
    virtual void scale() = 0;
  };
}

#endif
