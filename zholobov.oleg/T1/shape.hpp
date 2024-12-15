#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>

#include "base-types.hpp"

namespace zholobov {

  class Shape {
   public:
    virtual ~Shape() = default;
    virtual float getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t p) = 0;
    virtual void move(float dx, float dy) = 0;
    virtual void scale(float k) = 0;
  };

}

#endif
