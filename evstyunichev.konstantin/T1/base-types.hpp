#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace evstyunichev
{
  struct point_t
  {
    double x, y;
    point_t & operator+=(point_t &b);
    point_t operator+(const point_t &b) const;
    point_t operator-(const point_t &b) const;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  double findDist(point_t, point_t);

}
#endif
