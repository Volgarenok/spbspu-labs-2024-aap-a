#ifndef FABRIC_SHAPE_HPP
#define FABRIC_SHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace gavrilova {
  Shape * fabric_shape(std::istream & in, point_t & center, double & koef, size_t & nError);
}
#endif
