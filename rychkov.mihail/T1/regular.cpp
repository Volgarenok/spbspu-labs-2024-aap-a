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
  center_(center),
  nSides_(0),
  sideLength_(0),
  rotationAngle_(0)
{
  constexpr int epsilonCoef = 1000;
  double len1Sqr = getDistanceSqr(center, p2);
  double len2Sqr = getDistanceSqr(center, p3);
  double hypotenuseSqr = std::max(len1Sqr, len2Sqr);
  double innerRadiusSqr = std::min(len1Sqr, len2Sqr);
  double halfSideLengthSqr = getDistanceSqr(p2, p3);
  if (!isAlmostEqual(hypotenuseSqr, innerRadiusSqr + halfSideLengthSqr, epsilonCoef))
  {
    throw std::invalid_argument("invalid right triangle");
  }

  double nSides = PI / std::acos(std::sqrt(innerRadiusSqr / hypotenuseSqr));
  if (!isAlmostEqual(nSides, std::round(nSides), epsilonCoef))
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
