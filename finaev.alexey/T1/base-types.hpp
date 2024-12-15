#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace finaev
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    point_t pos;
    double wedth;
    double height;
  };
}

#endif
