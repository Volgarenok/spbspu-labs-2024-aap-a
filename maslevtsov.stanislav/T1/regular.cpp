#include "regular.hpp"
#include <stdexcept>
#include <cmath>

namespace maslevtsov
{
  bool isRightTriangle(point_t p1, point_t p2, point_t p3);
}

bool maslevtsov::isRightTriangle(point_t p1, point_t p2, point_t p3)
{
  double sqrLength1 = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
  double sqrLength2 = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
  double sqrLength3 = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
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
{
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double leg1 = std::sqrt(sqrLength1 < sqrLength2 ? sqrLength1 : sqrLength2);
  double leg2 = std::pow(pnt2_.x - pnt3_.x, 2) + std::pow(pnt2_.y - pnt3_.y, 2);
  double hypotenuse = std::sqrt(sqrLength1 > sqrLength2 ? sqrLength1 : sqrLength2);
  double angle = std::acos(leg1 / hypotenuse);
  double nTriangles = 360 / angle;
  double triangleSquare = 0.5 * leg1 * leg2;
  return triangleSquare * nTriangles;
}

maslevtsov::rectangle_t maslevtsov::Regular::getFrameRect() const noexcept
{
  rectangle_t frameRect;
  frameRect.pos = center_;
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double hypotenuse = std::sqrt(sqrLength1 > sqrLength2 ? sqrLength1 : sqrLength2);
  point_t movedCenter1 = {center_.x + hypotenuse, center_.y + hypotenuse};
  point_t movedCenter2 = {center_.x - hypotenuse, center_.y - hypotenuse};
  frameRect.width = std::abs(movedCenter2.x - movedCenter1.x);
  frameRect.height = std::abs(movedCenter2.y - movedCenter1.y);
  return frameRect;
}

void maslevtsov::Regular::move(point_t pnt) noexcept
{
  center_ = pnt;
  double movedX = pnt.x - getFrameRect().pos.x;
  double movedY = pnt.y - getFrameRect().pos.y;
  pnt2_ = {pnt2_.x + movedX, pnt2_.y + movedX};
  pnt3_ = {pnt3_.x + movedX, pnt3_.y + movedY};
}

void maslevtsov::Regular::move(double dx, double dy) noexcept
{
  center_ = {center_.x + dx, center_.y + dy};
  pnt2_ = {pnt2_.x + dx, pnt2_.y + dy};
  pnt3_ = {pnt3_.x + dx, pnt3_.y + dy};
}

void maslevtsov::Regular::scale(double k) noexcept
{
  pnt2_ = {pnt2_.x * k, pnt2_.y * k};
  pnt3_ = {pnt3_.x * k, pnt3_.y * k};
}

maslevtsov::Regular* maslevtsov::makeRegular(const double* arguments)
{
  Regular* reg = new Regular({arguments[0], arguments[1]}, {arguments[2], arguments[3]}, {arguments[4], arguments[5]});
  return reg;
}
