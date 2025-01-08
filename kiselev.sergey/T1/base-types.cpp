#include "base-types.hpp"
void kiselev::scalePoint(point_t p, point_t centre, double k)
{
  p.x = centre.x + (p.x - centre.x) * k;
  p.y = centre.y + (p.y - centre.y) * k;
}
