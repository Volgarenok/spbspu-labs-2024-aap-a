#ifndef BUILD_SHAPES_HPP
#define BUILD_SHAPES_HPP
#include <iostream>
#include "shape.hpp"

namespace sveshnikov
{
  void build_rectangle(std::istream &in, Shape **shapes, size_t &num_shapes);
  void build_ring(std::istream &in, Shape **shapes, size_t &num_shapes);
  void build_ellipse(std::istream &in, Shape **shapes, size_t &num_shapes);
}

#endif