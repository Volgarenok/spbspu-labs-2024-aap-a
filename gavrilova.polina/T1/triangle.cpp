#include "triangle.hpp"
#include <iostream>

namespace {
  bool isTriangle(gavrilova::point_t a, gavrilova::point_t b, gavrilova::point_t c) noexcept{
    double ab = a.getDistance(b);
    double bc = b.getDistance(c);
    double ac = c.getDistance(a);
    return ( (ab + bc) > ac && (ab + ac) > bc && (ac + bc) > ab && ab && ac && bc );
  }
}

gavrilova::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  if (!isTriangle(a, b, c)) {
    throw std::logic_error("Invalid arguments for triangle");
  }
}
gavrilova::Triangle::Triangle(const Triangle& other):
  a_(other.a_),
  b_(other.b_),
  c_(other.c_)
{}

double gavrilova::Triangle::getArea() const noexcept {
  return std::abs(((a_.x * (b_.y - c_.y) +  b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y))) / 2.0);
}

gavrilova::rectangle_t gavrilova::Triangle::getFrameRect() const noexcept {
  double minX = std::min(std::min(a_.x, b_.x), c_.x);
  double maxX = std::max(std::max(a_.x, b_.x), c_.x);
  double minY = std::min(std::min(a_.y, b_.y), c_.y);
  double maxY = std::max(std::max(a_.y, b_.y), c_.y);
  double height = maxY - minY;
  double width = maxX- minX;
  point_t pos {(maxX - minX) / 2 + minX, (maxY - minY) / 2 + minY};
  return {width, height, pos};
}
void gavrilova::Triangle::move(const point_t& p) noexcept {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Triangle::move(double difX, double difY) noexcept {
  a_.move(difX, difY);
  b_.move(difX, difY);
  c_.move(difX, difY);
}
void gavrilova::Triangle::scale_without_check(double k) noexcept {
  point_t center =  getFrameRect().pos;
  a_.scaleDistance(center, k);
  b_.scaleDistance(center, k);
  c_.scaleDistance(center, k);
}
gavrilova::Shape* gavrilova::Triangle::clone() const {
  return new Triangle(*this);
}

