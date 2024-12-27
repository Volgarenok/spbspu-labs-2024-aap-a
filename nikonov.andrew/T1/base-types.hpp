#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace nikonov
{
  struct point_t
  {
    point_t();
    point_t(double x, double y);
    double x;
    double y;
  };
  struct rectangle_t
  {
    rectangle_t(point_t lbp, point_t rtp);
    double width;
    double height;
    point_t pos;
  };
}
#endif
