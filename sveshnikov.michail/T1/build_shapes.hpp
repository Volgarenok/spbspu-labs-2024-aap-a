#ifndef BUILD_SHAPES_HPP
#define BUILD_SHAPES_HPP
#include <iostream>
#include "shape.hpp"

namespace sveshnikov
{
  Shape *buildShape(std::istream &in, std::string shape_name);
}

#endif
