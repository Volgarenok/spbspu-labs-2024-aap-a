#include "geometric_calculations.hpp"
#include <cmath>
#include "base-types.hpp"

double petrov::calculateDistBtwPoints(const petrov::point_t & p1, const petrov::point_t & p2)
{
  return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

void petrov::changeCoordinates(petrov::point_t ** points, size_t number_of_points, double dx, double dy)
{
  for (size_t i = 0; i < number_of_points; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void petrov::changeCoordinatesDueToScaling(petrov::point_t ** points, const petrov::point_t & pos, size_t number_of_points, double scale_value)
{
  for (size_t i = 0; i < number_of_points; i++)
  {
    points[i]->x = pos.x + (points[i]->x - pos.x) * scale_value;
    points[i]->y = pos.y + (points[i]->y - pos.y) * scale_value;
  }
}
