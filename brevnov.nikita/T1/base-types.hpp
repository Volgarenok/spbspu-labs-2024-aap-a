#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace brevnov
{
  struct point_t
  {
    point_t() = default;
    point_t(double x, double y):
      x_(x),
      y_(y)
      {}
    double x_;
    double y_;
  };
  struct rectangle_t
  {
    rectangle_t() = default;
    rectangle_t(double width, double height, point_t pos):
      width_(width),
      height_(height),
      pos_(pos)
      {}
    double width_;
    double height_;
    point_t pos_;
  };
}
#endif
