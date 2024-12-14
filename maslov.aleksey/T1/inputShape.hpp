#ifndef INPUT_SHAPE_HPP
#define INPUT_SHAPE_HPP

#include "shape.hpp"
#include "rectangle.hpp"
#include <iostream>

namespace maslov
{
  size_t inputShapes(std::istream & in, Shape ** shapes);
  Rectangle * makeRectangle(std::istream & in);
}

#endif
