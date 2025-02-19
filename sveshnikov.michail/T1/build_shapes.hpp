#ifndef BUILD_SHAPES_HPP
#define BUILD_SHAPES_HPP
#include <iostream>
#include "composite-shape.hpp"

namespace sveshnikov
{
  Shape *buildRectangle(std::istream &in);
  Shape *buildRing(std::istream &in);
  Shape *buildEllipse(std::istream &in);
  Shape *buildSquare(std::istream &in);
}

#endif
