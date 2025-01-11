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
  double getDistanceSqr(point_t from, point_t to) noexcept;
  double getSquare(point_t p1, point_t p2, point_t p3) noexcept;
  void move(point_t& p1, double deltaX, double deltaY) noexcept;
  rectangle_t makeFrame(point_t bottomLeft, point_t topRight) noexcept;
  void updateFrame(point_t& bottomLeft, point_t& topRight, point_t newPoint) noexcept;
  void updateFrame(point_t& bottomLeft, point_t& topRight,
      point_t bottomLeft2, point_t topRight2) noexcept;
  void convert(const rectangle_t& frame, point_t& bottomLeft, point_t& topRight) noexcept;
}

#endif
