#include "regular.hpp"

#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <math.hpp>

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
  center_(center)
{
  constexpr int epsilonCoef = 60;
  double len1Sqr = getDistanceSqr(center, p2);
  double len2Sqr = getDistanceSqr(center, p3);
  double hypotenuseSqr = std::max(len1Sqr, len2Sqr);
  double innerRadiusSqr = std::min(len1Sqr, len2Sqr);
  double halfSideLengthSqr = getDistanceSqr(p2, p3);
  if (!rychkov::isAlmostEqual(hypotenuseSqr, innerRadiusSqr + halfSideLengthSqr, epsilonCoef))
  {
    throw std::invalid_argument("invalid right triangle");
  }

  double nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
  if (!rychkov::isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
  {
    throw std::invalid_argument("invalid sides count");
  }
  nSides_ = std::round(nSides);
  sideLength_ = std::sqrt(halfSideLengthSqr) * 2;
  if (hypotenuseSqr == len1Sqr)
  {
    rotationAngle_ = std::fmod(std::acos((p2.y - center.y) / std::sqrt(hypotenuseSqr)), 2 * PI / nSides_);
  }
  else
  {
    rotationAngle_ = std::fmod(std::acos((p3.y - center.y) / std::sqrt(hypotenuseSqr)), 2 * PI / nSides_);
  }
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
    bottomLeft.x = std::min(bottomLeft.x, outerRadius * std::sin(angle));
    bottomLeft.y = std::min(bottomLeft.y, outerRadius * std::cos(angle));
    topRight.x = std::max(topRight.x, outerRadius * std::sin(angle));
    topRight.y = std::max(topRight.y, outerRadius * std::cos(angle));
    angle += sectorAngle;
  }
  point_t frameCenter = {(topRight.x + bottomLeft.x) / 2 + center_.x,
      center_.y + (topRight.y + bottomLeft.y) / 2};
  return {topRight.y - bottomLeft.y, topRight.x - bottomLeft.x, frameCenter};
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
