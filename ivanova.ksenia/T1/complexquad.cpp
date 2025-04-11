#include "complexquad.hpp"
#include "tools.hpp"
#include <cmath>
namespace
{
  double getLengthSide(ivanova::point_t point1, ivanova::point_t point2)
  {
    return std::sqrt(std::pow(point2.x - point1.x, 2) + std::pow(point2.y - point1.y, 2));
  }
  bool isTriangle(ivanova::point_t point1, ivanova::point_t point2, ivanova::point_t point3)
  {
    const double length1 = getLengthSide(point1, point2);
    const double length2 = getLengthSide(point1, point3);
    const double length3 = getLengthSide(point3, point2);
    return length1 < length2 + length3 || length2 < length1 + length3 || length3 < length1 + length2;
  }
  ivanova::point_t findP(ivanova::point_t p1, ivanova::point_t p2, ivanova::point_t p3, ivanova::point_t p4,
    bool& isIntersect)
  {
    const double a1 = p2.y - p1.y;
    const double b1 = p2.x - p1.x;
    const double c1 = p1.x * a1 + p1.y * b1;
    const double a2 = p4.y - p3.y;
    const double b2 = p4.x - p3.x;
    const double c2 = p3.x * a2 + p3.y * b2;
    const double determiner = a1 * b2 - b1 * a2;
    if (determiner == 0)
    {
      isIntersect = false;
      return { 0, 0 };
    }
    isIntersect = true;
    const double x = (c1 * b2 - c2 * b1) / determiner;
    const double y = (a2 * a1 - a2 * c1) / determiner;
    return { x, y };
  }
}

ivanova::Complexquad::Complexquad(point_t point1, point_t point2, point_t point3, point_t point4):
  point1_(point1),
  point2_(point2),
  point3_(point3),
  point4_(point4)
{
  bool isIntersect = true;
  point_t centre = findP(point1, point2, point3, point4, isIntersect);
  if (isTriangle(point1, point4, centre) || !isTriangle(point2, point3, centre) || !isIntersect ||
  (point4.x > point1.x && point3.x > point1.x))
  {
    throw std::invalid_argument("Segments do not intersect");
  }
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
