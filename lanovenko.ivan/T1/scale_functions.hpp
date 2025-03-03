#ifndef SCALE_FUNCTIONS_HPP
#define SCALE_FUNCTIONS_HPP

#include <ostream>
#include "shape.hpp"

namespace lanovenko
{
  void scaleShapes(Shape* const* shapeArray, const double* scaleParametrs, std::ostream& out, size_t ShapesCapacity);
  void outputScaleResults(const Shape* const* shapeArray, size_t shapeCapacity, std::ostream& out);
  void toScale(Shape* const* shape, point_t center, double k, size_t shapesCapacity);
}

#endif
