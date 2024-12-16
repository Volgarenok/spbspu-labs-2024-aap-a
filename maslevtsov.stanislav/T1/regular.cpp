#include "regular.hpp"
#include <cmath>
#include <stdexcept>

namespace maslevtsov
{
  bool isRightTriangle(point_t p1, point_t p2, point_t p3);
}

bool maslevtsov::isRightTriangle(point_t p1, point_t p2, point_t p3)
{
  double sqrLength1 = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
  double sqrLength2 = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
  double sqrLength3 = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
  return (p1.x != 0 || p1.y != 0 || p2.x != 0 || p2.y != 0 || p3.x != 0 || p3.y != 0) &&
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
  double smallRadius = std::sqrt(std::min(sqrLength1, sqrLength2));
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength2));
  std::size_t nVertices = std::round(M_PI / std::acos(smallRadius / bigRadius));
  return ((nVertices * std::pow(bigRadius, 2)) / 2) * std::sin((2 * M_PI) / nVertices);
}

maslevtsov::rectangle_t maslevtsov::Regular::getFrameRect() const noexcept
{
  rectangle_t frameRect;
  frameRect.pos = center_;
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength2));
  double smallRadius = std::sqrt(std::min(sqrLength1, sqrLength2));
  std::size_t nVertices = std::round(M_PI / std::acos(smallRadius / bigRadius));
  double maxX = 0, maxY = 0, minX = 0, minY = 0;
  double angle = 2 * M_PI / nVertices;
  for (std::size_t i = 0; i < nVertices; ++i)
  {
    double nextAngle = i * angle;
    maxX = std::max(maxX, center_.x + bigRadius * std::cos(nextAngle));
    maxY = std::max(maxY, center_.y + bigRadius * std::sin(nextAngle));
    minX = std::min(minX, center_.x + bigRadius * std::cos(nextAngle));
    minY = std::min(minY, center_.y + bigRadius * std::sin(nextAngle));
  }
  frameRect.width = maxX - minX;
  frameRect.height = maxY - minY;
  return frameRect;
}

void maslevtsov::Regular::move(point_t pnt) noexcept
{
  double movedX = pnt.x - getFrameRect().pos.x;
  double movedY = pnt.y - getFrameRect().pos.y;
  pnt2_ = {pnt2_.x + movedX, pnt2_.y + movedX};
  pnt3_ = {pnt3_.x + movedX, pnt3_.y + movedY};
  center_ = pnt;
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
