#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace sveshnikov
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

  point_t movePoint(point_t p, double dx, double dy);
  point_t scalingMovePoint(point_t p, point_t ctr, double k);
}

#endif
