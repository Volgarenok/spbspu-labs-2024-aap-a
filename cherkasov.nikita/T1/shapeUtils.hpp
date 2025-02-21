#ifndef SHAPE_UTILS
#define SHAPE_UTILS
#include "base-types.hpp"

namespace cherkasov
{
  void scalePoint(point_t& vertex, const point_t& center, double k);
  void moveVertex(point_t& vertex, double moveX, double moveY);
}
#endif