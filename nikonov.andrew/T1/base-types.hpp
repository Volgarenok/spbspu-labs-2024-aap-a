#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace nikonov
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
  void movePoint(point_t &pt, double x, double y);
}
#endif
