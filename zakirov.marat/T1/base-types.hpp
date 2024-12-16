#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zakirov
{
  struct point_t
  {
    public:
      double x_;
      double y_;
  };

  struct rectangle_t
  {
    public:
      double width_;
      double height_;
      point_t position_;
  };

  double get_distance_x(point_t first_p, point_t second_p);
  double get_distance_y(point_t first_p, point_t second_p);
  double get_distance(point_t first_p, point_t second_p);
  point_t get_middle(point_t first_p, point_t second_p);
}

#endif