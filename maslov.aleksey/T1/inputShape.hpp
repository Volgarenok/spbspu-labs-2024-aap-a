#ifndef INPUT_SHAPE_HPP
#define INPUT_SHAPE_HPP

#include "shape.hpp"
#include "rectangle.hpp"
#include "scaleData.hpp"
#include <iostream>

namespace maslov
{
  maslov::ScaleData inputShape(std::istream & in, Shape ** shapes);
  Rectangle * makeRectangle(std::istream & in);
}

#endif