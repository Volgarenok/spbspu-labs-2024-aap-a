#ifndef KIZHIN_T1_SHAPE_UTILS_HPP
#define KIZHIN_T1_SHAPE_UTILS_HPP

#include <string>
#include "shape.hpp"

namespace kizhin {
  Shape* createShape(const std::string&, const double*);
  void scaleShapes(Shape* const*, size_t, const double*);
  double computeTotalArea(const Shape* const*, size_t size);
  void deleteShapes(Shape* const*, size_t&);
}

#endif

