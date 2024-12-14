#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace rychkov
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    double height, width;
    point_t pos;
  };
}

#endif
