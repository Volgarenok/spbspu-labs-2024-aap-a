#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace brevnov
{
  struct point_t
  {
    point_t() = default;
    point_t(double xf, double yf):
      x(x),
      y(y)
      {}
    double x;
    double y;
  };
  struct rectangle_t
  {
    rectangle_t() = default;
    rectangle_t(double widthf, double heightf, point_t posf):
      width(widthf),
      height(heightf),
      pos(posf)
      {}
    double width;
    double height;
    point_t pos;
  };
}
#endif
