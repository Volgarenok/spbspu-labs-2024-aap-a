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
  double getDistanceSqr(point_t from, point_t to);
  double getSquare(point_t p1, point_t p2, point_t p3);
  rectangle_t makeFrame(point_t bottomLeft, point_t topRight);
}

#endif
