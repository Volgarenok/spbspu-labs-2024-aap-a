#include "shapesProcess.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "shape.hpp"
#include "base-types.hpp"
constexpr double inaccuracy = 0.0000000001;
double alymova::getVector(point_t p1, point_t p2)
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
bool alymova::isRectanglurTriangle(point_t p1, point_t p2, point_t p3)
{
  if (std::abs(std::pow(getVector(p2, p3), 2) + std::pow(getVector(p1, p3), 2) - std::pow(getVector(p1, p2), 2)) < inaccuracy)
  {
    return true;
  }
  return false;
}
