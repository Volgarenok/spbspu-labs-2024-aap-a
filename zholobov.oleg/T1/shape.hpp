#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>

#include "base-types.hpp"

namespace zholobov {

  class Shape {
   public:
    virtual ~Shape() = default;
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };

}

#endif
