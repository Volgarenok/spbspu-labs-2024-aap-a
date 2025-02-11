#include "circle.hpp"
#include <stdexcept>

sharifullina::Circle::Circle(point_t center, double radius):
  Ellipse(center, radius, radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius must be positive.");
  }
}
