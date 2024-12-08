#include "triangle.hpp"
#include "base-types.hpp"
#include <cmath>
#include <iostream>

bool gavrilova::isTriangle(point_t A, point_t B, point_t C) {
  double AB = gavrilova::getDistance(A, B);
  double AC = gavrilova::getDistance(A, C);
  double BC = gavrilova::getDistance(B, C);
  return ( (AB + BC) >= AC && (AB + AC) >= BC && (AC + BC) >= AB && AB && AC && BC );
}
double gavrilova::getDistance(point_t A, point_t B){
  return std::sqrt(std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2));
}

gavrilova::Triangle::Triangle(point_t A, point_t B, point_t C)
{
  if (gavrilova::isTriangle(A, B, C)){
    A_.x = A.x;
    B_.x = B.x;
    C_.x = C.x;
    A_.y = A.y;
    B_.y = B.y;
    C_.y = C.y;
    center_.x = (A_.x + B_.x + C_.x) / 3;
    center_.y = (A_.y + B_.y + C_.y) / 3;
  } else {
    throw std::logic_error("Invalid arguments for triangle");
  }
}
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
  resultRect.pos.x = (maxX- minX)/2;
  resultRect.pos.y = (maxY - minY)/2;
  return resultRect;
}
void gavrilova::Triangle::move(point_t p) {
  double difX = p.x - center_.x;
  double difY = p.y - center_.y;
  A_.x += difX;
  A_.y += difY;
  B_.x += difX;
  B_.y += difY;
  C_.x += difX;
  C_.y += difY;
  center_.x = p.x;
  center_.y = p.y;
}
void gavrilova::Triangle::move(double difX, double difY) {
  A_.x += difX;
  A_.y += difY;
  B_.x += difX;
  B_.y += difY;
  C_.x += difX;
  C_.y += difY;
}
void gavrilova::Triangle::scale(double k) {
  A_.x = center_.x - (center_.x - A_.x) / 2 * k;
  A_.y = center_.y - (center_.y - A_.y) / 2 * k;
  B_.x = center_.x - (center_.x - B_.x) / 2 * k;
  B_.y = center_.y - (center_.y - B_.y) / 2 * k;
  C_.x = center_.x - (center_.x - C_.x) / 2 * k;
  C_.y = center_.y - (center_.y - C_.y) / 2 * k;
}
