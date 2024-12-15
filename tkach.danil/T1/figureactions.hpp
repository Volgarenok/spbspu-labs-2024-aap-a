#ifndef FIGUREACTIONS_HPP
#define FIGUREACTIONS_HPP

#include <cstddef>
#include <fstream>
#include "shape.hpp"

namespace tkach
{
  void deleteShapes(tkach::Shape** shape_array, size_t counter_of_shapes);
  double getTotalArea(tkach::Shape** shape_array, size_t counter_of_shapes);
  void printCoordinatesOfFrameRect(std::ostream& out, tkach::Shape** shape_array, size_t counter_of_shapes);
  void doIsoScaleShapes(tkach::Shape** shape_array, size_t counter_of_shapes, double scale_coef, const tkach::point_t& scale_point);
}

#endif
