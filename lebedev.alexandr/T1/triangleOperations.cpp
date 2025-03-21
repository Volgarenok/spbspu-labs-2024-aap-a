#include "triangleOperations.hpp"
#include <cmath>

double lebedev::triangleArea(point_t p1, point_t p2, point_t p3)
{
  return 0.5 * std::fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

bool lebedev::isTriangle(point_t p1, point_t p2, point_t p3)
{
  double area = triangleArea(p1, p2, p3);
  return (area != 0);
}

bool lebedev::isPointInsideTriangle(point_t p1, point_t p2, point_t p3, point_t p4)
{
  double s = triangleArea(p1, p2, p3);
  double s1 = triangleArea(p1, p2, p4);
  double s2 = triangleArea(p2, p3, p4);
  double s3 = triangleArea(p1, p3, p4);
  return ((s == s1 + s2 + s3) && (s1 != 0 && s2 != 0 && s3 != 0));
}
