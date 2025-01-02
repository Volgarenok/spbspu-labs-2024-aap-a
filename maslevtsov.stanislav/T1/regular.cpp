#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>

namespace
{
  bool isRightTriangle(maslevtsov::point_t p1, maslevtsov::point_t p2, maslevtsov::point_t p3)
  {
    double sqrLength1 = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
    double sqrLength2 = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
    double sqrLength3 = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
    return (sqrLength1 != 0 || sqrLength2 != 0 || sqrLength3 != 0) &&
           ((sqrLength1 + sqrLength2 == sqrLength3) || (sqrLength2 + sqrLength3 == sqrLength1) ||
            (sqrLength1 + sqrLength3 == sqrLength2));
  }

  bool isRightSize(std::size_t nVertices, double smallRadius, double bigRadius)
  {
    return std::abs((std::cos(M_PI / std::round(nVertices))) - (smallRadius / bigRadius)) < 1e-10;
  }
}

maslevtsov::Regular::Regular(point_t center, point_t pnt2, point_t pnt3):
  center_(center),
  pnt2_(pnt2),
  pnt3_(pnt3)
{
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(pnt2_.x - pnt3_.x, 2) + std::pow(pnt2_.y - pnt3_.y, 2);
  double sqrLength3 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  std::size_t nVertices = M_PI / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength3));
  if (!isRightTriangle(center, pnt2, pnt3) || !isRightSize(nVertices, std::sqrt(sqrSmallRadius), bigRadius))
  {
    throw std::logic_error("incorrect regular input");
  }
}

double maslevtsov::Regular::getArea() const noexcept
{
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(pnt2_.x - pnt3_.x, 2) + std::pow(pnt2_.y - pnt3_.y, 2);
  double sqrLength3 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  std::size_t nVertices = std::round(M_PI / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse)));
  double sideLength = 2 * std::sqrt(sqrLength1 + sqrLength2 + sqrLength3 - sqrHypotenuse - sqrSmallRadius);
  return (std::pow(sideLength, 2) * nVertices) / (4 * std::tan(M_PI / nVertices));
}

maslevtsov::rectangle_t maslevtsov::Regular::getFrameRect() const noexcept
{
  double sqrLength1 = std::pow(center_.x - pnt2_.x, 2) + std::pow(center_.y - pnt2_.y, 2);
  double sqrLength2 = std::pow(pnt2_.x - pnt3_.x, 2) + std::pow(pnt2_.y - pnt3_.y, 2);
  double sqrLength3 = std::pow(center_.x - pnt3_.x, 2) + std::pow(center_.y - pnt3_.y, 2);
  double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
  double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
  std::size_t nVertices = std::round(M_PI / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse)));
  double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength3));
  double maxX = std::numeric_limits<double>::min(), minX = std::numeric_limits<double>::max();
  double maxY = std::numeric_limits<double>::min(), minY = std::numeric_limits<double>::max();
  double angle = std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
  if (center_.y == pnt3_.y)
  {
    angle = 0;
  }
  for (std::size_t i = 0; i < nVertices; ++i)
  {
    double nextAngle = i * 2 * M_PI / nVertices + angle;
    minX = std::min(minX, center_.x + bigRadius * std::cos(nextAngle));
    minY = std::min(minY, center_.y + bigRadius * std::sin(nextAngle));
    maxX = std::max(maxX, center_.x + bigRadius * std::cos(nextAngle));
    maxY = std::max(maxY, center_.y + bigRadius * std::sin(nextAngle));
  }
  rectangle_t frameRect = {maxX - minX, maxY - minY, center_};
  return frameRect;
}

void maslevtsov::Regular::move(point_t pnt) noexcept
{
  double movedX = pnt.x - center_.x;
  double movedY = pnt.y - center_.y;
  move(movedX, movedY);
}

void maslevtsov::Regular::move(double dx, double dy) noexcept
{
  center_ = {center_.x + dx, center_.y + dy};
  pnt2_ = {pnt2_.x + dx, pnt2_.y + dy};
  pnt3_ = {pnt3_.x + dx, pnt3_.y + dy};
}

void maslevtsov::Regular::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  pnt2_ = {center_.x + (pnt2_.x - center_.x) * k, center_.y + (pnt2_.y - center_.y) * k};
  pnt3_ = {center_.x + (pnt3_.x - center_.x) * k, center_.y + (pnt3_.y - center_.y) * k};
}

maslevtsov::Regular* maslevtsov::makeRegular(const double* arguments)
{
  Regular* reg = new Regular({arguments[0], arguments[1]}, {arguments[2], arguments[3]}, {arguments[4], arguments[5]});
  return reg;
}
