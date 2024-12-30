#include "base-types.hpp"
void nikonov::movePoint(point_t &pt, double x, double y)
{
  pt.x += x;
  pt.y += y;
}
