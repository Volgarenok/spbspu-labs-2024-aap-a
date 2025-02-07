#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace tkach
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
  void addToPoint(point_t& change_point, double add_to_x, double add_to_y);
  point_t getShiftedPointFromAnother(const point_t& first_point, const point_t& another_point, double multiplier);
  double getCoordDistMultiplied(double point1_coord, double point2_coord, double multiplier);
}

#endif
