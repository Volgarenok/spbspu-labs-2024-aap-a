#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace abramov
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

  double getLength(const point_t &p1, const point_t &p2);
  void changePointCoords(point_t &p, double dx, double dy);
}
#endif
