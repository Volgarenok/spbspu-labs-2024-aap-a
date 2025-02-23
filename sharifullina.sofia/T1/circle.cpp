#include "circle.hpp"
#include <stdexcept>

sharifullina::Circle::Circle(point_t center, double radius):
  Ellipse(center, radius, radius)
{}
