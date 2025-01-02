#ifndef KIZHIN_T1_SHAPE_UTILS_HPP
#define KIZHIN_T1_SHAPE_UTILS_HPP

#include <iosfwd>
#include "shape.hpp"

namespace kizhin {
  Shape* createShape(const std::string&, const double*);
  void scaleShapes(Shape* const*, const double*);
  double computeTotalArea(const Shape* const*);
  void deleteShapes(Shape* const*);
}

#endif

