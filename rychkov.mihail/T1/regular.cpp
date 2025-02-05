#include "regular.hpp"

#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <math.hpp>

namespace rychkov
{
  static double getDistanceSqrEpsilon(point_t p1, point_t p2, double coef)
  {
    if (p1.x > p2.x)
    {
      std::swap(p1.x, p2.x);
    }
    if (p1.y > p2.y)
    {
      std::swap(p1.y, p2.y);
    }
    double maxXLen = p2.x - p1.x + (getEpsilon(p2.x, true) + getEpsilon(p1.x, false)) * coef;
    double minXLen = p2.x - p1.x - (getEpsilon(p2.x, false) - getEpsilon(p1.x, true)) * coef;
    double maxYLen = p2.y - p1.y + (getEpsilon(p2.y, true) + getEpsilon(p1.y, false)) * coef;
    double minYLen = p2.y - p1.y - (getEpsilon(p2.y, false) - getEpsilon(p1.y, true)) * coef;
    double maxDistanceSqr = maxXLen * maxXLen + maxYLen * maxYLen;
    double minDistanceSqr = minXLen * minXLen + minYLen * minYLen;
    double distanceSqr = getDistanceSqr(p1, p2);
    return std::max(maxDistanceSqr - distanceSqr, distanceSqr - minDistanceSqr);
  }
  static double getEpsilonForRegular(point_t center, point_t p2, point_t p3)
  {
    constexpr int epsilonCoefBase = 60;
    double epsilon1 = getDistanceSqrEpsilon(center, p2, epsilonCoefBase);
    double epsilon2 = getDistanceSqrEpsilon(center, p3, epsilonCoefBase);
    double epsilon3 = getDistanceSqrEpsilon(p2, p3, epsilonCoefBase);

    double epsilon = epsilon1 + epsilon2 + epsilon3;
    return epsilonCoefBase * epsilon;
  }
  static long getNSides(double innerRadiusSqr, double hypotenuseSqr, double epsilonCoef)
  {
    double nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
    if (!isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
    {
      throw std::invalid_argument("invalid sides count");
    }
    return std::round(nSides);
  }
}

rychkov::Regular::Regular(point_t center, size_t nSides, double sideLength, double rotationAngle):
  center_(center),
  nSides_(nSides),
  sideLength_(sideLength),
  rotationAngle_(rotationAngle)
{
  if ((nSides < 3) || (sideLength <= 0))
  {
    throw std::invalid_argument("invalid regular");
  }
}
rychkov::Regular::Regular(point_t center, point_t p2, point_t p3):
  center_(center),
  nSides_(0),
  sideLength_(0),
  rotationAngle_(0)
{
  double hypotenuseSqr = getDistanceSqr(center, p2);
  double innerRadiusSqr = getDistanceSqr(center, p3);
  double halfsideSqr = getDistanceSqr(p2, p3);
  if (hypotenuseSqr < innerRadiusSqr)
  {
    std::swap(hypotenuseSqr, innerRadiusSqr);
    std::swap(p2, p3);
  }

  double epsilonCoef = 1 + getEpsilonForRegular(center, p2, p3) / getEpsilon(hypotenuseSqr, true);
  if (!isAlmostEqual(hypotenuseSqr, innerRadiusSqr + halfsideSqr, epsilonCoef))
  {
    throw std::invalid_argument("invalid right triangle");
  }

  nSides_ = getNSides(innerRadiusSqr, hypotenuseSqr, epsilonCoef);
  sideLength_ = std::sqrt(halfsideSqr) * 2;
  rotationAngle_ = std::acos((p2.y - center.y) / std::sqrt(hypotenuseSqr));
}

double rychkov::Regular::getArea() const noexcept
{
  return sideLength_ * sideLength_ * nSides_ / 4 / std::tan(PI / nSides_);
}
rychkov::rectangle_t rychkov::Regular::getFrameRect() const noexcept
{
  double outerRadius = (sideLength_ / 2) / std::sin(PI / nSides_);
  double sectorAngle = 2 * PI / nSides_;
  point_t bottomLeft{0, 0}, topRight{0, 0};

  double angle = rotationAngle_;
  for (size_t i = 0; i < nSides_; i++)
  {
    updateFrame(bottomLeft, topRight, {outerRadius * std::sin(angle), outerRadius * std::cos(angle)});
    angle += sectorAngle;
  }
  rectangle_t result = makeFrame(bottomLeft, topRight);
  rychkov::move(result.pos, center_.x, center_.y);
  return result;
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
void rychkov::Regular::unsafeScale(double coef) noexcept
{
  sideLength_ *= coef;
}
rychkov::Shape* rychkov::Regular::clone() const
{
  Regular* result = static_cast< Regular* >(malloc(sizeof(Regular)));
  if (!result)
  {
    return nullptr;
  }
  return new (result) Regular(*this);
}
