#include "shape.hpp"
#include <cstddef>

void savintsev::scaleRelativeTo(Shape * rhs, point_t p, double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t center = rhs->getFrameRect().pos;
  point_t new_center = {(center.x - p.x) * k + p.x, (center.y - p.y) * k + p.y};
  rhs->move(new_center);
  rhs->scale(k);
}
