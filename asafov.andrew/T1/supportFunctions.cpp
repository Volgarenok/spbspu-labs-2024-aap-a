#include "supportFunctions.hpp"

void asafov::scalePoint(asafov::point_t& point, asafov::point_t fpoint, double scale)
{
  point.x += (point.x - fpoint.x) * (scale - 1);
  point.y += (point.y - fpoint.y) * (scale - 1);
}
