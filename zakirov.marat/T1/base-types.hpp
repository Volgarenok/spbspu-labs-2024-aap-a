#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zakirov
{
  struct point_t
  {
    public:
      double x;
      double y;
  };

  struct rectangle_t
  {
    public:
      double width;
      double height;
      point_t pos;
  };

  double get_distance_x(point_t first_p, point_t second_p);
  double get_distance_y(point_t first_p, point_t second_p);
  double get_distance(point_t first_p, point_t second_p);
  point_t get_middle(point_t first_p, point_t second_p);
  void move_point(point_t object, point_t target);
  void move_point(point_t object, double bias_x, double bias_y);
}

#endif
