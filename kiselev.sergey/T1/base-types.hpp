#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace kiselev
{
  class point_t
  {
  public:
    double x;
    double y;
  };
  class rectangle_t
  {
  public:
    double width;
    double height;
    point_t pos;
  };
  point_t scalePoint(point_t p, point_t centre, double k);
  point_t movePoint(point_t p, double dx, double dy);
}
#endif
