#include "base-types.hpp"
#include <cmath>

double zakirov::get_distance_x(point_t first_p, point_t second_p)
{
  return std::abs(first_p.x - second_p.x);
}

double zakirov::get_distance_y(point_t first_p, point_t second_p)
{
  return std::abs(first_p.y - second_p.y);
}

double zakirov::get_distance(point_t first_p, point_t second_p)
{
  double squared_x = std::pow(get_distance_x(first_p, second_p), 2);
  double squared_y = std::pow(get_distance_y(first_p, second_p), 2);
  return std::sqrt(squared_x + squared_y);
}

zakirov::point_t zakirov::get_middle(point_t first_p, point_t second_p)
{
  double middle_x = (first_p.x + second_p.x) / 2;
  double middle_y = (first_p.y + second_p.y) / 2;
  return {middle_x, middle_y};
}
