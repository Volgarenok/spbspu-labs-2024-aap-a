#include "base-types.hpp"

maslov::point_t maslov::scalePoint(point_t point, point_t center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
  return {point.x, point.y};
}
