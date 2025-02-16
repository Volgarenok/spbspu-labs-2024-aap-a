#include "base-types.hpp"
#include <cmath>

double zakirov::get_distance(const point_t & first_p, const point_t & second_p)
{
  double squared_x = std::pow(first_p.x - second_p.x, 2);
  double squared_y = std::pow(first_p.y - second_p.y, 2);
  return std::sqrt(squared_x + squared_y);
}

zakirov::point_t zakirov::get_middle(const point_t & first_p, const point_t & second_p)
{
  double middle_x = (first_p.x + second_p.x) / 2;
  double middle_y = (first_p.y + second_p.y) / 2;
  return {middle_x, middle_y};
}

void zakirov::move_point(point_t & object, double bias_x, double bias_y)
{
  object = {object.x + bias_x, object.y + bias_y};
}
