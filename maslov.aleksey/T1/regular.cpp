#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <limits>
#include "costants.hpp"

maslov::Regular::Regular(point_t A, point_t B, point_t C):
  A_(A),
  B_(B),
  C_(C),
  n_(getVerticals())
{
  if (!isRegular())
  {
    throw std::invalid_argument("Regular does not exist");
  }
}
double maslov::Regular::getArea() const
{
  double rI = getRadiusIncircle();
  double halfSide = getHalfSide();
  return halfSide * n_ * rI;
}
maslov::rectangle_t maslov::Regular::getFrameRect() const
{
  double centerX = A_.x;
  double centerY = A_.y;
  double rC = getRadiusCircumcircle();
  double halfSide = getHalfSide();
  double AB = getDistance(A_, B_);
  double value = halfSide / rC;
  double initialAngle = std::acos(value);
  if (AB == rC)
  {
    if (B_.y == centerY)
    {
      initialAngle = 0;
    }
  }
  else if (C_.y == centerY)
  {
    initialAngle = 0;
  }
  double maxX = std::numeric_limits< double >::min();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::min();
  double minY = std::numeric_limits< double >::max();
  for (size_t i = 0; i < n_; ++i)
  {
    double angle = initialAngle + 2 * maslov::pi * i / n_;
    double x = std::round((centerX + rC * std::cos(angle)) * 100.0) / 100.0;
    double y = std::round((centerY + rC * std::sin(angle)) * 100.0) / 100.0;
    maxX = std::max(maxX, x);
    minX = std::min(minX, x);
    maxY = std::max(maxY, y);
    minY = std::min(minY, y);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  return {width, height,{centerX, centerY}};
}
void maslov::Regular::move(point_t s)
{
  double dx = s.x - A_.x;
  double dy = s.y - A_.y;
  A_ = {s.x, s.y};
  B_ = {B_.x + dx, B_.y + dy};
  C_ = {C_.x + dx, C_.y + dy};
}
void maslov::Regular::move(double dx, double dy)
{
  A_ = {A_.x + dx, A_.y + dy};
  B_ = {B_.x + dx, B_.y + dy};
  C_ = {C_.x + dx, C_.y + dy};
}
void maslov::Regular::scaleWithoutCheck(double k)
{
  B_.x = A_.x + (B_.x - A_.x) * k;
  B_.y = A_.y + (B_.y - A_.y) * k;
  C_.x = A_.x + (C_.x - A_.x) * k;
  C_.y = A_.y + (C_.y - A_.y) * k;
}
double maslov::Regular::getDistance(point_t A, point_t B) const
{
  return std::sqrt(std::pow(B.x - A.x, 2.0) + std::pow(B.y - A.y, 2.0));
}
double maslov::Regular::getRadiusIncircle() const
{
  double AB = getDistance(A_, B_);
  double AC = getDistance(A_, C_);
  double BC = getDistance(B_, C_);
  return std::max(std::min(AB, AC), BC);
}
double maslov::Regular::getRadiusCircumcircle() const
{
  double AB = getDistance(A_, B_);
  double AC = getDistance(A_, C_);
  return std::max(AB, AC);
}
double maslov::Regular::getHalfSide() const
{
  double AB = getDistance(A_, B_);
  double AC = getDistance(A_, C_);
  double BC = getDistance(B_, C_);
  return std::min(AB, std::min(AC, BC));
}
namespace
{
  bool isGreaterDouble(double a, double b)
  {
    return a > b;
  }
}
size_t maslov::Regular::getVerticals() const
{
  double hyp = getRadiusCircumcircle();
  double cat1 = getHalfSide();
  double cat2 = getRadiusIncircle();
  double x = cat1, y = cat2, z = hyp;
  double value = (x * x - z * z - y * y) / (-2 * y * z);
  double angle = std::acos(value) * 180.0 / maslov::pi;
  double verticals = 360.0 / (angle * 2);
  double doubleToCheck = std::fabs(verticals - std::round(verticals));
  if (isGreaterDouble(doubleToCheck, maslov::customEpsilonForVerticals))
  {
    return 0;
  }
  return std::round(verticals);
}
bool maslov::Regular::isRegular() const
{
  double hyp = getRadiusCircumcircle();
  double cat1 = getHalfSide();
  double cat2 = getRadiusIncircle();
  double doubleToCheck = std::fabs(hyp * hyp - (cat1 * cat1 + cat2 * cat2));
  if (isGreaterDouble(doubleToCheck, maslov::customEpsilonForPythagoras))
  {
    if (n_ != 0)
    {
      return true;
    }
  }
  return false;
}
maslov::Shape * maslov::Regular::clone() const
{
  return new Regular(A_, B_, C_);
}
