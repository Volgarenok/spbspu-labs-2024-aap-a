#include "regular.hpp"
#include <cmath>
#include <algorithm>
#include <limits>

maslov::Regular::Regular(point_t A, point_t B, point_t C):
A_(A), B_(B), C_(C), AB_(distance(A, B)),
AC_(distance(A, C)), BC_(distance(B, C)),
rI_(findRadiusIncircle(AC_, AB_, BC_)),
rC_(findRadiusCircumcircle(AC_, AB_)),
halfSide_(findHalfSide(AC_, AB_, BC_)) {};
double maslov::Regular::getArea() const
{
  size_t n = getVerticals();
  double semiP = halfSide_ * n;
  return 0.5 * semiP * rI_;
}
maslov::rectangle_t maslov::Regular::getFrameRect() const
{
  size_t n = getVerticals();
  double centerX = A_.x;
  double centerY = A_.y;
  double R = rC_;
  double maxX = std::numeric_limits< double >::min();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::min();
  double minY = std::numeric_limits< double >::max();
  for (size_t i = 0; i < n; ++i)
  {
    double angle = 2 * M_PI * i / n;
    double x = centerX + R * std::cos(angle);
    double y = centerY + R * std::sin(angle);
    if (y > maxY)
    {
      maxY = y;
    }
    if (y < minY)
    {
      minY = y;
    }
    if (x > maxX) {
      maxX = x;
    }
    if (x < minX)
    {
      minX = x;
    }
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
  return std::min(AB, AC, BC);
}
size_t maslov::Regular::getVerticals() const
{
  double x = halfSide_, y = rC_, z = rI_;
  double value = (x * x - z * z - y * y) / (-2 * y * z);
  double angle = std::acos(value) * 180.0 / M_PI;
  size_t verticals = static_cast<size_t>(std::round(360.0 / angle));
  return verticals;
}
bool maslov::isRegular(point_t A, point_t B, point_t C)
{
  double AB = distance(A, B);
  double AC = distance(A, C);
  double BC = distance(B, C);
  double hyp = std::max(AB, AC);
  double cat1 = BC;
  double cat2 = (AB + AC + BC) - hyp - cat1;
  if (std::abs(hyp * hyp - (cat1 * cat1 + cat2 * cat2)) > 1e-9)
  {
    double semiP = (AB + BC+ AC) / 2;
    double area = std::sqrt(semiP * (semiP - AB) * (semiP - BC) * (semiP - AC));
    double radiusCircumcircle = (AB * BC * AC) / (4 * area);
    double radiusIncircle = area / semiP;
    bool checkRadius = (cat1 == radiusIncircle) || (cat2 = radiusIncircle);
    checkRadius = checkRadius && (radiusCircumcircle == hyp);
    if (checkRadius)
    {
      return true;
    }
  }
  return false;
}