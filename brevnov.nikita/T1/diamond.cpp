#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

brevnov::Diamond(point_t center, point_t horizontal, point_t vertical) : center(center), horizontal(horizontal), vertical(vertical)
{
}

double brevnov::Diamond::getArea()
{
  return (std::fabs((horizontal.x - center.x) * (vertical.y - center.y) * 2))
}

rectangle brevnov::Diamond::getFrameRect()
{
  rectangle_t result;
  result.pos = center;
  result.width = std::fabs(horizontal.x - center.x) * 2;
  result.height = std::fabs(vertical.y - center.y) * 2;
  return result;
}

void brevnov::Diamond::move(point_t new_centre)
{
  double xdif = horizontal.x - center.x;
  double ydif = vertical.y - center.y;
  center = new_centre;
  horizontal = new_centre;
  vertical = new_centre;
  horizontal.x += xdif;
  vertical.y += ydif;
}

void brevnov::Diamond::move(double dx, double dy)
{
  center.x += dx;
  horizontal.x += dx;
  vertical.x += dx;
  center.y += dy;
  horizontal.y += dy;
  vertical.y += dy;
}

void brevnov::Diamond::scale(double n)
{
  if (n <= 0)
  {
    throw std::invalid_argument("Invalid coefficient");
  }
  horizontal.x = center.x + (center.x - horizontal.x) * n;
  vertical.y = center.y + (center.y - vertical.y) * n;
}
