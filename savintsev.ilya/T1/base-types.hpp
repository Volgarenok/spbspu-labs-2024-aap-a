#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace savintsev
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

  double getLength(point_t lhs, point_t rhs);
  bool isPointInTriangle(point_t t1, point_t t2, point_t t3, point_t p);
  point_t findLinesIntersect(point_t m1, point_t m2, point_t n1, point_t n2, bool * finded);
  double getTriangleArea(point_t p1, point_t p2, point_t p3);
  bool isTriangle(point_t p1, point_t p2, point_t p3);
}
#endif
