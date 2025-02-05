#ifndef MAKE_SHAPE_HPP
#define MAKE_SHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace gavrilova {
  Shape* make_Shape(std::istream& in, point_t& center, double& koef, size_t& nError);
}
#endif
