#ifndef MAKE_SHAPE_HPP
#define MAKE_SHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace gavrilova {
  Shape* make_shape(std::istream& in, std::string shapeType, size_t& nError);
}
#endif
