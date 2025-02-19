#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zakirov
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  double get_distance(const point_t & first_p, const point_t & second_p);
  point_t get_middle(const point_t & first_p, const point_t & second_p);
  void move_point(point_t & object, double bias_x, double bias_y);
}

#endif
