#ifndef GEOM_FUNC_HPP
#define GEOM_FUNC_HPP
#include "shape.hpp"

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count);
  void outputFrameCoordinates(Shape** shapes, size_t count);
}

#endif
