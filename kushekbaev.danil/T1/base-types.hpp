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
    double length;
    point_t pos;
  };
}

#endif
