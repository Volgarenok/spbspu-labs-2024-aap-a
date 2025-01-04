#ifndef PROCESSHAPE_HPP
#define PROCESSHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace cherkasov
{
  double calculArea(Shape** shapes, size_t shape);
  void deleteShapes(Shape** shapes, size_t shape);
  void outputFrameCoordinates(Shape** shapes, size_t shape);
  void scaling(Shape** shapes, size_t shape, point_t p, double scalingFactor);
}
#endif
