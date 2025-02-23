#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace bocharov
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
  point_t scalePoint(point_t p, point_t pos, double ratio);
  point_t movePoint(point_t p, double dx, double dy);
  point_t scalePoint(point_t p, double ratio);
}
#endif
