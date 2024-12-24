#ifdef PROCESSHAPE_HPP
#define PROCESSHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace cherkasov
{
  double calculArea(Shape* shapes[], size_t shapeCount);
  void deleteShapes(Shape* shapes[], size_t& shapeCount)
  void outputFrameCoordinates(Shape* shapes[], size_t shapeCount);
  void scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor);
}
#endif
