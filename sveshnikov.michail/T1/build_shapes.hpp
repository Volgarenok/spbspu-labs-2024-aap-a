#ifndef BUILD_SHAPES_HPP
#define BUILD_SHAPES_HPP
#include <iostream>
#include "composite-shape.hpp"

namespace sveshnikov
{
  Shape *buildRectangle(std::istream &in, CompositeShape &comp_shp);
  Shape *buildRing(std::istream &in, CompositeShape &comp_shp);
  Shape *buildEllipse(std::istream &in, CompositeShape &comp_shp);
  Shape *buildSquare(std::istream &in, CompositeShape &comp_shp);
}

#endif
