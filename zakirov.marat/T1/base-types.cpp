#include "base-types.hpp"
#include <cmath>

double zakirov::get_distance_x(zakirov::point_t first_p, zakirov::point_t second_p)
{
  double big_num = first_p.x_ > second_p.x_ ? first_p.x_ : second_p.x_;
  double small_num = first_p.x_ > second_p.x_ ? second_p.x_ : first_p.x_;
  return big_num - small_num;
}

double zakirov::get_distance_y(zakirov::point_t first_p, zakirov::point_t second_p)
{
  double big_num = first_p.y_ > second_p.y_ ? first_p.y_ : second_p.y_;
  double small_num = first_p.y_ > second_p.y_ ? second_p.y_ : first_p.y_;
  return big_num - small_num;
}

double zakirov::get_distance(zakirov::point_t first_p, zakirov::point_t second_p)
{
  double squared_x = pow(zakirov::get_distance_x(first_p, second_p), 2);
  double squared_y = pow(zakirov::get_distance_y(first_p, second_p), 2);
  return sqrt(squared_x + squared_y);
}

zakirov::point_t zakirov::get_middle(point_t first_p, point_t second_p)
{
  double middle_x = (first_p.x_ + second_p.x_) / 2;
  double middle_y = (first_p.y_ + second_p.y_) / 2;
  point_t middle;

  middle.x_ = middle_x;
  middle.y_ = middle_y;

  return middle;
}
