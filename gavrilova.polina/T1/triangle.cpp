#include "triangle.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

namespace {
  double getDistance(gavrilova::point_t A, gavrilova::point_t B){
    return std::sqrt(std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2));
  }
  bool isTriangle(gavrilova::point_t A, gavrilova::point_t B, gavrilova::point_t C) {
    double AB = getDistance(A, B);
    double AC = getDistance(A, C);
    double BC = getDistance(B, C);
    return ( (AB + BC) > AC && (AB + AC) > BC && (AC + BC) > AB && AB && AC && BC );
  }
}

gavrilova::Triangle::Triangle(point_t A, point_t B, point_t C):
  A_({0.0}),
  B_({0.0}),
  C_({0.0})
{
  if (!isTriangle(A, B, C)) {
    throw std::logic_error("Invalid arguments for triangle");
  }
  A_ = A;
  B_ = B;
  C_ = C;
}
gavrilova::Triangle::Triangle(const Triangle& other):
  A_(other.A_),
  B_(other.B_),
  C_(other.C_)
{}

double gavrilova::Triangle::getArea() const
{
    double S = std::abs(((A_.x * (B_.y - C_.y) +
                         B_.x * (C_.y - A_.y) +
                         C_.x * (A_.y - B_.y))) / 2.0);
    return S;
}
gavrilova::rectangle_t gavrilova::Triangle::getFrameRect() const {
  rectangle_t resultRect;
  double minX = std::min(std::min(A_.x, B_.x), C_.x);
  double maxX = std::max(std::max(A_.x, B_.x), C_.x);
  double minY = std::min(std::min(A_.y, B_.y), C_.y);
  double maxY = std::max(std::max(A_.y, B_.y), C_.y);
  resultRect.height = maxY - minY;
  resultRect.width = maxX- minX;
  resultRect.pos.x = (maxX - minX) / 2 + minX;
  resultRect.pos.y = (maxY - minY) / 2 + minY;
  return resultRect;
}
void gavrilova::Triangle::move(point_t p) {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Triangle::move(double difX, double difY) {
  A_.move(difX, difY);
  B_.move(difX, difY);
  C_.move(difX, difY);
}
void gavrilova::Triangle::scale(double k) {
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  point_t center =  getFrameRect().pos;
  A_.x = center.x - (center.x - A_.x) * k;
  A_.y = center.y - (center.y - A_.y) * k;
  B_.x = center.x - (center.x - B_.x) * k;
  B_.y = center.y - (center.y - B_.y) * k;
  C_.x = center.x - (center.x - C_.x) * k;
  C_.y = center.y - (center.y - C_.y) * k;
}
gavrilova::Shape* gavrilova::Triangle::clone() const {
  return new Triangle(*this);
}
gavrilova::Triangle& gavrilova::Triangle::operator=(const gavrilova::Triangle& rhs) {
  A_ = rhs.A_;
  B_ = rhs.B_;
  C_ = rhs.C_;
  return *this;
}
