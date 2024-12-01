#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace savintsev
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

  double getLength(point_t lhs, point_t rhs);
}
#endif
