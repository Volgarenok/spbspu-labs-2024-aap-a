#include "base-types.hpp"
kiselev::point_t kiselev::scalePoint(point_t p, point_t centre, double k)
{
  p.x = centre.x + (p.x - centre.x) * k;
  p.y = centre.y + (p.y - centre.y) * k;
  return { p.x, p.y };
}
