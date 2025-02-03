#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace maslov
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
  point_t scalePoint(point_t point, point_t center, double k);
}

#endif
