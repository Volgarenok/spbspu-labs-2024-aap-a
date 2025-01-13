#include "auxiliaryFunctions.hpp"
#include <cmath>

double lebedev::max(double a, double b, double c)
{
  double d = std::fmax(a, b);
  return std::fmax(d, c);
}

double lebedev::min(double a, double b, double c)
{
  double d = std::fmin(a, b);
  return std::fmin(d, c);
}

double lebedev::triangleArea(point_t p1, point_t p2, point_t p3)
{
  return 0.5 * std::fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

bool lebedev::isTriangle(point_t p1, point_t p2, point_t p3)
{
  double area = lebedev::triangleArea(p1, p2, p3);
  if (area == 0)
  {
    return false;
  }
  return true;
}

bool lebedev::isPointInsideTriangle(point_t p1, point_t p2, point_t p3, point_t p4)
{
  double s = lebedev::triangleArea(p1, p2, p3);
    double s1 = lebedev::triangleArea(p1, p2, p4);
    double s2 = lebedev::triangleArea(p2, p3, p4);
    double s3 = lebedev::triangleArea(p1, p3, p4);
    return ((s == s1 + s2 + s3) && (s1 != 0 && s2 != 0 && s3 != 0));
}

void lebedev::deleteShapePtr(lebedev::Shape** shps, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shps[i];
  }
}

lebedev::point_t lebedev::getMiddlePoint(point_t p1, point_t p2)
{
  return { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
}
