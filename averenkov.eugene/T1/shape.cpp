#include "shape.hpp"

namespace averenkov
{
  double getLine(point_t a, point_t b)
  {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
  }
}
