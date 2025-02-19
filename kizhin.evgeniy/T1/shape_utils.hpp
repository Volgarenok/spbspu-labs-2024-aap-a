#ifndef KIZHIN_T1_SHAPE_UTILS_HPP
#define KIZHIN_T1_SHAPE_UTILS_HPP

#include <iosfwd>
#include "composite_shape.hpp"

namespace kizhin {
  Shape* createShape(const std::string&, const double*);
  void scaleShapes(CompositeShape&, const double*);
  void unsafeScaleShapes(CompositeShape&, const double*);
  Shape* scaleShape(Shape*, double, const point_t&);
}

#endif

