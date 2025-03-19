#include "concave.hpp"
#include "tools.hpp"
#include <cmath>

ivanova::Concave::Concave(point_t cnPoint1, point_t cnPoint2, point_t cnPoint3, point_t cnPoint4):
 cnPoint1_(cnPoint1),
 cnPoint2_(cnPoint2),
 cnPoint3_(cnPoint3),
 cnPoint4_(cnPoint4)
{
}

double ivanova::Concave::getArea() const
{
  double A = vectorLength(cnPoint1_, cnPoint2_);
  double B = vectorLength(cnPoint1_, cnPoint3_);
  double C = vectorLength(cnPoint2_, cnPoint3_);
  double p1 = (A + B + C) / 2;
  double S1 = std::sqrt(p1 * (p1 - A) * (p1 - B) * (p1 - C));
  double a = vectorLength(cnPoint2_, cnPoint4_);
  double b = vectorLength(cnPoint3_, cnPoint4_);
  double p2 = (a + b + C) / 2;
  double S2 = std::sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - C));
  return S1 - S2;
}

ivanova::rectangle_t ivanova::Concave::getFrameRect() const
{
  double leftest = std::fmin(cnPoint1_.x, std::fmin(cnPoint2_.x, cnPoint3_.x));
  double rightest = std::fmax(cnPoint1_.x, std::fmax(cnPoint2_.x, cnPoint3_.x));
  double lowest = std::fmin(cnPoint1_.y, std::fmin(cnPoint2_.y, cnPoint3_.y));
  double highest = std::fmax(cnPoint1_.y, std::fmax(cnPoint2_.y, cnPoint3_.y));
  point_t center = {leftest + (rightest - leftest) / 2, lowest + (highest - lowest) / 2};
  return {rightest - leftest, highest - lowest, center};
}

void ivanova::Concave::move(point_t point)
{
  double moveX = point.x - cnPoint4_.x;
  double moveY = point.y - cnPoint4_.y;
  cnPoint1_ = {cnPoint1_.x + moveX, cnPoint1_.y + moveY};
  cnPoint2_ = {cnPoint2_.x + moveX, cnPoint2_.y + moveY};
  cnPoint3_ = {cnPoint3_.x + moveX, cnPoint3_.y + moveY};
  cnPoint4_ = point;
}

void ivanova::Concave::move(double x, double y)
{
  cnPoint1_ = {cnPoint1_.x + x, cnPoint1_.y + y};
  cnPoint2_ = {cnPoint2_.x + x, cnPoint2_.y + y};
  cnPoint3_ = {cnPoint3_.x + x, cnPoint3_.y + y};
  cnPoint4_ = {cnPoint4_.x + x, cnPoint4_.y + y};
}

void ivanova::Concave::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive.");
  }
  point_t pos = getFrameRect().pos;
  cnPoint1_.x = pos.x + (cnPoint1_.x - pos.x) * ratio;
  cnPoint1_.y = pos.y + (cnPoint1_.y - pos.y) * ratio;
  cnPoint2_.x = pos.x + (cnPoint2_.x - pos.x) * ratio;
  cnPoint2_.y = pos.y + (cnPoint2_.y - pos.y) * ratio;
  cnPoint3_.x = pos.x + (cnPoint3_.x - pos.x) * ratio;
  cnPoint3_.y = pos.y + (cnPoint3_.y - pos.y) * ratio;
  cnPoint4_.x = pos.x + (cnPoint4_.x - pos.x) * ratio;
  cnPoint4_.y = pos.y + (cnPoint4_.y - pos.y) * ratio;
}
