#ifndef FIGUREACTIONS_HPP
#define FIGUREACTIONS_HPP

#include <cstddef>
#include <iostream>
#include "shape.hpp"
#include "composite-shape.hpp"

namespace tkach
{
  void doSaveIsoScaleCompShape(CompositeShape& shape_array, double scale_coef, const point_t& scale_point);
  void doUnsaveIsoScaleCompShape(CompositeShape& shape_array, double scale_coef, const point_t& scale_point);
  void doSaveIsoScaleShapes(Shape* const* shape_array, size_t counter_of_shapes, double scale_coef,
    const point_t& scale_point);
  void doSaveIsoScaleOneShape(Shape* shape, double scale_coef, const point_t& scale_point);
  void doUnsaveIsoScaleShapes(Shape* const* shape_array, size_t counter_of_shapes, double scale_coef,
    const point_t& scale_point);
  void doUnsaveIsoScaleOneShape(Shape* shape, double scale_coef, const point_t& scale_point);
}

#endif
