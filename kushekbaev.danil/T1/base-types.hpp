#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace kushekbaev
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

  void moveDelta(const double dx, const double dy, point_t point);
  void isoScaling(const double V, const point_t middle, point_t point);
}

#endif
