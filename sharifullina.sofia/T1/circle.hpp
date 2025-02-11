#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "ellipse.hpp"

namespace sharifullina
{
  class Circle: public Ellipse
  {
  public:
    Circle(point_t center, double radius);
  };
}

#endif
