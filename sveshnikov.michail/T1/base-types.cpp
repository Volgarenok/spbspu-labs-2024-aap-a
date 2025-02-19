#include "base-types.hpp"

sveshnikov::point_t sveshnikov::movePoint(point_t p, double dx, double dy)
{
  return {p.x + dx, p.y + dy};
}

sveshnikov::point_t sveshnikov::scalingMovePoint(point_t p, point_t ctr, double k)
{
  return {ctr.x + k * (p.x - ctr.x), ctr.y + k * (p.y - ctr.y)};
}
