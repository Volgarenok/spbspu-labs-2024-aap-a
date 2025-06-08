#include "base-types.hpp"

komarova::point_t komarova::scalePoint(point_t p, point_t center, double coef)
{
  p.x = center.x + (p.x - center.x) * coef;
  p.y = center.y + (p.y - center.y) * coef;
  return p;
}

