#include "regular.hpp"
#include <stdexcept>

namespace maslevtsov
{
  bool isRightTriangle(point_t p1, point_t p2, point_t p3);
}

bool maslevtsov::isRightTriangle(point_t p1, point_t p2, point_t p3)
{
  double sqrLength1 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  double sqrLength2 = (p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y);
  double sqrLength3 = (p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y);
  return (p1.x != 0 && p1.y != 0 && p2.x != 0 && p2.y != 0 && p3.x != 0 && p3.y != 0) &&
    ((sqrLength1 + sqrLength2 == sqrLength3) || (sqrLength2 + sqrLength3 == sqrLength1) ||
     (sqrLength1 + sqrLength3 == sqrLength2));
}

maslevtsov::Regular::Regular(point_t center, point_t pnt2, point_t pnt3):
  center_(center),
  pnt2_(pnt2),
  pnt3_(pnt3)
{
  if (!isRightTriangle(center, pnt2, pnt3))
  {
    throw std::logic_error("incorrect coordinates");
  }
}

double maslevtsov::Regular::getArea() const noexcept
{}

maslevtsov::rectangle_t maslevtsov::Regular::getFrameRect() const noexcept
{}

void maslevtsov::Regular::move(point_t pnt) noexcept
{}

void maslevtsov::Regular::move(double dx, double dy) noexcept
{}

void maslevtsov::Regular::scale(double k) noexcept
{}

maslevtsov::Regular* maslevtsov::makeRegular(const double* arguments)
{}
