#include "regular.hpp"

#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <math.hpp>

namespace rychkov
{
  double getDistanceSqr(point_t p1, point_t p2)
  {
    double deltaX = p1.x - p2.x;
    double deltaY = p1.y - p2.y;
    return deltaX * deltaX + deltaY * deltaY;
  }
}

rychkov::Regular::Regular(point_t center, size_t nSides, double sideLength):
  center_(center),
  nSides_(nSides),
  sideLength_(sideLength)
{
  if((nSides < 3) || (sideLength <= 0))
  {
    throw std::invalid_argument("invalid regular");
  }
}
rychkov::Regular::Regular(point_t p1, point_t p2, point_t p3)
{
  constexpr int epsilonCoef = 60;
  double len1Sqr = getDistanceSqr(p1, p2);
  double len2Sqr = getDistanceSqr(p2, p3);
  double len3Sqr = getDistanceSqr(p3, p1);
  double hypotenuseSqr = std::max({len1Sqr, len2Sqr, len3Sqr});
  double innerRadiusSqr = std::min({len1Sqr, len2Sqr, len3Sqr});
  double leg2Sqr = len1Sqr + len2Sqr + len3Sqr - hypotenuseSqr - innerRadiusSqr;
  if (!rychkov::isAlmostEqual(std::sqrt(hypotenuseSqr), std::sqrt(innerRadiusSqr) + std::sqrt(leg2Sqr), epsilonCoef))
  {
    throw std::invalid_argument("invalid right triangle");
  }

  double nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
  if (!rychkov::isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
  {
    std::swap(innerRadiusSqr, leg2Sqr);
    nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
    if (!rychkov::isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
    {
      throw std::invalid_argument("invalid sides count");
    }

  }
  nSides_ = std::round(nSides);
  sideLength_ = std::sqrt(len1Sqr + len2Sqr + len3Sqr - hypotenuseSqr - innerRadiusSqr) * 2;
  if ((len1Sqr == hypotenuseSqr) && (len2Sqr == innerRadiusSqr))
  {
    center_ = p2;
  }
  else if ((len2Sqr == hypotenuseSqr) && (len3Sqr == innerRadiusSqr))
  {
    center_ = p3;
  }
  else
  {
    center_ = p1;
  }
}

double rychkov::Regular::getArea() const noexcept
{
  return sideLength_ * sideLength_ * nSides_ / 4 / std::tan(PI / nSides_);
}
rychkov::rectangle_t rychkov::Regular::getFrameRect() const noexcept
{
  double outerRadius = sideLength_ / 2 / std::sin(PI / nSides_);
  return {outerRadius * 2, outerRadius * 2, center_};
}
void rychkov::Regular::move(point_t destination) noexcept
{
  center_ = destination;
}
void rychkov::Regular::move(double deltaX, double deltaY) noexcept
{
  center_.x += deltaX;
  center_.y += deltaY;
}
void rychkov::Regular::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
  sideLength_ *= coef;
}
