#include "complexquad.hpp"
#include "tools.hpp"
#include <cmath>

ivanova::Complexquad::Complexquad(point_t point1, point_t point2, point_t point3, point_t point4):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  point4_(point4)
{
}

double ivanova::Complexquad::getArea() const
{
  point_t center = getFrameRect().pos;
  double A = vectorLength(point1_, point2_);
  double B = vectorLength(point1_, center);
  double C = vectorLength(point2_, center);
  double p1 = (A + B + C) / 2;
  double S1 = std::sqrt(p1 * (p1 - A) * (p1 - B) * (p1 - C));
  double a = vectorLength(point3_, point4_);
  double b = vectorLength(point3_, center);
  double c = vectorLength(point4_, center);
  double p2 = (a + b + c) / 2;
  double S2 = std::sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - C));
  return S1 + S2;
}

ivanova::rectangle_t ivanova::Complexquad::getFrameRect() const
{
  double leftest = std::fmin(std::fmin(point1_.x, point2_.x), std::fmin(point3_.x, point4_.x));
  double rightest = std::fmax(std::fmax(point1_.x, point2_.x), std::fmax(point3_.x, point4_.x));
  double lowest = std::fmin(std::fmin(point1_.y, point2_.y), std::fmin(point3_.y, point4_.y));
  double highest = std::fmax(std::fmax(point1_.y, point2_.y), std::fmax(point3_.y, point4_.y));
  point_t center = {leftest + (rightest - leftest) / 2, lowest + (highest - lowest) / 2};
  return {rightest - leftest, highest - lowest, center};
}

void ivanova::Complexquad::move(point_t point)
{
  point_t center = getFrameRect().pos;
  double moveX = point.x - center.x;
  double moveY = point.y - center.y;
  move(moveX, moveY);
}

void ivanova::Complexquad::move(double x, double y)
{
  point1_ = {point1_.x + x, point1_.y + y};
  point2_ = {point2_.x + x, point2_.y + y};
  point3_ = {point3_.x + x, point3_.y + y};
  point4_ = {point4_.x + x, point4_.y + y};
}

void ivanova::Complexquad::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Scale ratio must be positive.");
  }
  point_t pos = getFrameRect().pos;
  point1_.x = pos.x + (point1_.x - pos.x) * ratio;
  point1_.y = pos.y + (point1_.y - pos.y) * ratio;
  point2_.x = pos.x + (point2_.x - pos.x) * ratio;
  point2_.y = pos.y + (point2_.y - pos.y) * ratio;
  point3_.x = pos.x + (point3_.x - pos.x) * ratio;
  point3_.y = pos.y + (point3_.y - pos.y) * ratio;
  point4_.x = pos.x + (point4_.x - pos.x) * ratio;
  point4_.y = pos.y + (point4_.y - pos.y) * ratio;
}
