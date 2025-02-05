#include <cmath>
#include "base-types.hpp"


double zakirov::get_distance_x(const point_t & first_p, const point_t & second_p)
{
  return std::abs(first_p.x - second_p.x);
}

double zakirov::get_distance_y(const point_t & first_p, const point_t & second_p)
{
  return std::abs(first_p.y - second_p.y);
}

double zakirov::get_distance(const point_t & first_p, const point_t & second_p)
{
  double squared_x = std::pow(get_distance_x(first_p, second_p), 2);
  double squared_y = std::pow(get_distance_y(first_p, second_p), 2);
  return std::sqrt(squared_x + squared_y);
}

zakirov::point_t zakirov::get_middle(const point_t & first_p, const point_t & second_p)
{
  double middle_x = (first_p.x + second_p.x) / 2;
  double middle_y = (first_p.y + second_p.y) / 2;
  return {middle_x, middle_y};
}

void zakirov::move_point(point_t & object, point_t target)
{
  object.x = target.x;
  object.y = target.y;
}

void zakirov::move_point(point_t & object, double bias_x, double bias_y)
{
  move_point(object, {object.x + bias_x, object.y + bias_y});
}
