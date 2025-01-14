#ifndef BUILD_SHAPES_HPP
#define BUILD_SHAPES_HPP
#include <iostream>
#include "composite-shape.hpp"

namespace sveshnikov
{
  void build_rectangle(std::istream &in, CompositeShape &comp_shp);
  void build_ring(std::istream &in, CompositeShape &comp_shp);
  void build_ellipse(std::istream &in, CompositeShape &comp_shp);
  void build_square(std::istream &in, CompositeShape &comp_shp);
}

#endif
