#include "ellipse.hpp"
#include <cmath>

brevnov::Ellipse(point_t center, double r1, double r2) : center(center), r1(r1), r2(r2)
{
}

double brevnov::Ellipse::getArea()
{
  const p = std::acos(-1.0);
  return p * r1 * r2;
}

rectangle_t brevnov::Ellipse::getFrameRect()
{
  rectangle_t result;
  result.pos = center;
  result.width = r1 * 2;
  result.height = r2 * 2;
  return result;
}

void brevnov::Ellipse::move(point_t new_centre)
{
  center = new_centre;
}

void brevnov::Ellipse::move(double dx, double dy)
{
  center.x += dx;
  center.y += dy;
}

void brevnov::Ellipse::scale(double n)
{
  if (n <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  r1 *= n;
  r2 *= n;
}
