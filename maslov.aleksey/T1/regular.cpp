#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <limits>

maslov::Regular::Regular(point_t a, point_t b, point_t c):
  a_(a),
  b_(b),
  c_(c),
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
  double centerX = a_.x;
  double centerY = a_.y;
  double rC = getRadiusCircumcircle();
  double halfSide = getHalfSide();
  double ab = getDistance(a_, b_);
  double value = halfSide / rC;
  double initialAngle = std::acos(value);
  if (ab == rC)
  {
    if (b_.y == centerY)
    {
      initialAngle = 0;
    }
  }
  else if (c_.y == centerY)
  {
    initialAngle = 0;
  }
  double maxX = std::numeric_limits< double >::min();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::min();
  double minY = std::numeric_limits< double >::max();
  double pi = 4 * std::atan(1.0);
  for (size_t i = 0; i < n_; ++i)
  {
    double angle = initialAngle + 2 * pi * i / n_;
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
  double dx = s.x - a_.x;
  double dy = s.y - a_.y;
  move(dx, dy);
}
void maslov::Regular::move(double dx, double dy)
{
  a_ = {a_.x + dx, a_.y + dy};
  b_ = {b_.x + dx, b_.y + dy};
  c_ = {c_.x + dx, c_.y + dy};
}
void maslov::Regular::scaleWithoutCheck(double k)
{
  b_ = scalePoint(b_, a_, k);
  c_ = scalePoint(c_, a_, k);
}
double maslov::Regular::getDistance(point_t A, point_t B) const
{
  return std::sqrt(std::pow(B.x - A.x, 2.0) + std::pow(B.y - A.y, 2.0));
}
double maslov::Regular::getRadiusIncircle() const
{
  double ab = getDistance(a_, b_);
  double ac = getDistance(a_, c_);
  double bc = getDistance(b_, c_);
  return std::max(std::min(ab, ac), bc);
}
double maslov::Regular::getRadiusCircumcircle() const
{
  double ab = getDistance(a_, b_);
  double ac = getDistance(a_, c_);
  return std::max(ab, ac);
}
double maslov::Regular::getHalfSide() const
{
  double ab = getDistance(a_, b_);
  double ac = getDistance(a_, c_);
  double bc = getDistance(b_, c_);
  return std::min(ab, std::min(ac, bc));
}
namespace
{
  bool isEqualForVerticals(double a, double b)
  {
    constexpr double customEpsilonForVerticals = 1e-10;
    return std::fabs(a - b) > customEpsilonForVerticals;
  }
  bool isEqualForPythagoras(double a, double b)
  {
    constexpr double customEpsilonForPythagoras = 1e-20;
    return std::fabs(a - b) > customEpsilonForPythagoras;
  }
}
size_t maslov::Regular::getVerticals() const
{
  double pi = 4 * std::atan(1.0);
  double hyp = getRadiusCircumcircle();
  double cat1 = getHalfSide();
  double cat2 = getRadiusIncircle();
  double x = cat1, y = cat2, z = hyp;
  double value = (x * x - z * z - y * y) / (-2 * y * z);
  double angle = std::acos(value) * 180.0 / pi;
  double verticals = 360.0 / (angle * 2);
  if (isEqualForVerticals(verticals, std::round(verticals)))
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
  if (isEqualForPythagoras((hyp * hyp), (cat1 * cat1 + cat2 * cat2)))
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
  return new Regular(a_, b_, c_);
}
