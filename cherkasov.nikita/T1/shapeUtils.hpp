#ifndef SHAPE_UTILS
#define SHAPE_UTILS
#include "base-types.hpp"
#include "shape.hpp"

namespace cherkasov
{
  void scalePoint(point_t& point, const point_t& center, double k);
  void moveVertex(point_t& point, double moveX, double moveY);
}
#endif
