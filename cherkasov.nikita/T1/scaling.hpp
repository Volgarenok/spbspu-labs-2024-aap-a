#ifndef SCALING_H
#define SCALING_H
#include <cstddef>
#include "shape.hpp"

namespace cherkasov
{
  void scaling(Shape* shapes[], size_t shapeCount, point_t p, double scalingFactor);
}
#endif
