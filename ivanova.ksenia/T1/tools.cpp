#include "tools.hpp"
#include <cmath>

namespace ivanova
{
  bool operator ==(const ivanova::point_t a, const ivanova::point_t b);
}

double ivanova::vectorLength(point_t a, point_t b)
{
  return std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
