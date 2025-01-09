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
    double maxXLen = p2.x - p1.x + getEpsilon(p2.x, true) * coef + getEpsilon(p1.x, false) * coef;
    double minXLen = p2.x - p1.x - getEpsilon(p2.x, false) * coef - getEpsilon(p1.x, true) * coef;
    double maxYLen = p2.y - p1.y + getEpsilon(p2.y, true) * coef + getEpsilon(p1.y, false) * coef;
    double minYLen = p2.y - p1.y - getEpsilon(p2.y, false) * coef - getEpsilon(p1.y, true) * coef;
    double maxDistanceSqr = maxXLen * maxXLen + maxYLen * maxYLen;
    double minDistanceSqr = minXLen * minXLen + minYLen * minYLen;
    double distanceSqr = getDistanceSqr(p1, p2);
    return std::max(maxDistanceSqr - distanceSqr, distanceSqr - minDistanceSqr);
  }
}

rychkov::Regular::Regular(point_t center, size_t nSides, double sideLength, double rotationAngle):
  center_(center),
  nSides_(nSides),
  sideLength_(sideLength),
  rotationAngle_(rotationAngle)
{
  if((nSides < 3) || (sideLength <= 0))
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
  constexpr int epsilonCoefBase = 60;
  double hypotenuseSqr = getDistanceSqr(center, p2);
  double epsilon1 = getDistanceSqrEpsilon(center, p2, epsilonCoefBase);
  double innerRadiusSqr = getDistanceSqr(center, p3);
  double epsilon2 = getDistanceSqrEpsilon(center, p3, epsilonCoefBase);
  double halfsideSqr = getDistanceSqr(p2, p3);
  double epsilon3 = getDistanceSqrEpsilon(p2, p3, epsilonCoefBase);

  double epsilon = epsilon1 + epsilon2 + epsilon3;
  double epsilonCoef = epsilonCoefBase * (1 + epsilon / getEpsilon(hypotenuseSqr, true));

  if (hypotenuseSqr < innerRadiusSqr)
  {
    std::swap(hypotenuseSqr, innerRadiusSqr);
    std::swap(p2, p3);
  }
  if (!isAlmostEqual(hypotenuseSqr, innerRadiusSqr + halfsideSqr, epsilonCoef))
  {
    throw std::invalid_argument("invalid right triangle");
  }

  double nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
  if (!isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
  {
    throw std::invalid_argument("invalid sides count");
  }
  nSides_ = std::round(nSides);
  sideLength_ = std::sqrt(halfsideSqr) * 2;
  rotationAngle_ = std::fmod(std::acos((p2.y - center.y) / std::sqrt(hypotenuseSqr)), 2 * PI / nSides_);
  double tempAngle = rotationAngle_ + (rotationAngle_ > 0 ? -2 : 2) * PI / nSides_;
  if (std::abs(tempAngle) < std::abs(rotationAngle_))
  {
    rotationAngle_ = tempAngle;
  }
}

double rychkov::Regular::getArea() const noexcept
{
  return sideLength_ * sideLength_ * nSides_ / 4 / std::tan(PI / nSides_);
}
rychkov::rectangle_t rychkov::Regular::getFrameRect() const noexcept
{
  double outerRadius = (sideLength_ / 2) / std::sin(PI / nSides_);
  double sectorAngle = 2 * PI / nSides_;
  double angle = rotationAngle_;
  point_t bottomLeft{0, 0}, topRight{0, 0};
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
