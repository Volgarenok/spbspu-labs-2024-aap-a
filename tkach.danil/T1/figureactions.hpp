#ifndef FIGUREACTIONS_HPP
#define FIGUREACTIONS_HPP

#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace tkach
{
  void deleteShapes(tkach::Shape** shape_array, size_t counter_of_shapes);
  double getTotalArea(const tkach::Shape* const* shape_array, size_t counter_of_shapes);
  std::ostream& printCoordinatesOfAllFrameRects(std::ostream& out, const tkach::Shape* const* shape_array, size_t counter_of_shapes);
  void doSaveIsoScaleShapes(tkach::Shape* const* shape_array, size_t counter_of_shapes, double scale_coef, const tkach::point_t& scale_point);
  void doSaveIsoScaleOneShape(tkach::Shape* shape, double scale_coef, const tkach::point_t& scale_point);
  void doUnsaveIsoScaleShapes(tkach::Shape* const* shape_array, size_t counter_of_shapes, double scale_coef, const tkach::point_t& scale_point);
  void doUnsaveIsoScaleOneShape(tkach::Shape* shape, double scale_coef, const tkach::point_t& scale_point);
}

#endif
