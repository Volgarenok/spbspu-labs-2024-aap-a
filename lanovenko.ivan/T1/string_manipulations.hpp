#ifndef STRING_MANIPULATION_HPP
#define STRING_MANIPULATION_HPP
#include <ostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace lanovenko
{
  void scaleCommand(const char* str, Shape* const* shapeArray, size_t capacity, std::ostream& out);
  void scaleShapes(Shape* const* shapeArray, size_t shapeNumber, const double* arguments, std::ostream& out);
  void toScale(Shape* shape, const point_t center, const double k);
  void outputShapes(const Shape* const* shapeArray, size_t shapeNumbers, std::ostream& out);
}

#endif
