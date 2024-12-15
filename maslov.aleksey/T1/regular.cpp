#include "regular.hpp"
#include <cmath>
#include <algorithm>
#include <limits>

maslov::Regular::Regular(point_t A, point_t B, point_t C):
A_(A), B_(B), C_(C), AB_(distance(A, B)),
AC_(distance(A, C)), BC_(distance(B, C)),
rI_(findRadiusIncircle(AC_, AB_, BC_)),
rC_(findRadiusCircumcircle(AC_, AB_)),
halfSide_(findHalfSide(AC_, AB_, BC_)), 
n_(findVerticals(halfSide_, rI_, rC_))
{}
double maslov::Regular::getArea() const
{
  return halfSide_ * n_ * rI_;
}
maslov::rectangle_t maslov::Regular::getFrameRect() const
{
  double centerX = A_.x;
  double centerY = A_.y;
  double R = rC_;
  double maxX = std::numeric_limits< double >::min();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::min();
  double minY = std::numeric_limits< double >::max();
  double value = halfSide_ / rC_;
  double initialAngle = std::acos(value);
  if (AB_ == std::max(AB_, AC_))
  {
    if (B_.y == A_.y)
    {
      initialAngle = 0;
    }
  }
  else if (C_.y == A_.y)
  {
    initialAngle = 0;
  }
  for (size_t i = 0; i < n_; ++i)
  {
    double angle = initialAngle + 2 * M_PI * i / n_;
    double x = std::round((centerX + R * std::cos(angle)) * 100.0) / 100.0;
    double y = std::round((centerY + R * std::sin(angle)) * 100.0) / 100.0;
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
  AC_ = distance(A_, C_);
  BC_ = distance(B_, C_);
  rI_ = findRadiusIncircle(AC_, AB_, BC_);
  rC_ = findRadiusCircumcircle(AC_, AB_);
  halfSide_ = findHalfSide(AC_, AB_, BC_);
}
void maslov::Regular::move(double dx, double dy)
{
  A_ = {A_.x + dx, A_.y + dy};
  B_ = {B_.x + dx, B_.y + dy};
  C_ = {C_.x + dx, C_.y + dy};
  AB_ = distance(A_, B_);
  AC_ = distance(A_, C_);
  BC_ = distance(B_, C_);
  rI_ = findRadiusIncircle(AC_, AB_, BC_);
  rC_ = findRadiusCircumcircle(AC_, AB_);
  halfSide_ = findHalfSide(AC_, AB_, BC_);
}
void maslov::Regular::scale(double k)
{
  B_.x = A_.x + (B_.x - A_.x) * k;
  B_.y = A_.y + (B_.y - A_.y) * k;
  C_.x = A_.x + (C_.x - A_.x) * k;
  C_.y = A_.y + (C_.y - A_.y) * k;
  AB_ = distance(A_, B_);
  AC_ = distance(A_, C_);
  BC_ = distance(B_, C_);
  rI_ = findRadiusIncircle(AC_, AB_, BC_);
  rC_ = findRadiusCircumcircle(AC_, AB_);
  halfSide_ = findHalfSide(AC_, AB_, BC_);
}
double maslov::distance(point_t A, point_t B)
{
  return std::sqrt(std::pow(B.x - A.x, 2.0) + std::pow(B.y - A.y, 2.0));
}
double maslov::findRadiusIncircle(double AC, double AB, double BC)
{
  return std::max(std::min(AB, AC), BC);
}
double maslov::findRadiusCircumcircle(double AC, double AB)
{
  return std::max(AB, AC);
}
double maslov::findHalfSide(double AC, double AB, double BC)
{
  return std::min(AB, std::min(AC, BC));
}
size_t maslov::findVerticals(double cat1, double cat2, double hyp)
{
  double x = cat1, y = cat2, z = hyp;
  double value = (x * x - z * z - y * y) / (-2 * y * z);
  double angle = std::acos(value) * 180.0 / M_PI;
  double verticals = 360.0 / (angle * 2);
  if (std::abs(verticals - std::round(verticals)) > 1e-10)
  {
    return 0;
  }
  return std::round(verticals);
}

bool maslov::isRegular(point_t A, point_t B, point_t C)
{
  double AB = distance(A, B);
  double AC = distance(A, C);
  double BC = distance(B, C);
  double hyp = std::max(AB, AC);
  double cat1 = BC;
  double cat2 = std::min(AB, AC);
  if (std::abs(hyp * hyp - (cat1 * cat1 + cat2 * cat2)) > 1e-20)
  {
    if (findVerticals(std::min(cat1, cat2), std::max(cat1, cat2), hyp) != 0)
    {
      return true;
    }
  }
  return false;
}
