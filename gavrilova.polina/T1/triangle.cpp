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

gavrilova::Triangle::Triangle(point_t A, point_t B, point_t C):
A_({0.0}), B_({0.0}), C_({0.0})
{
  if (gavrilova::isTriangle(A, B, C)){
    A_.x = A.x;
    B_.x = B.x;
    C_.x = C.x;
    A_.y = A.y;
    B_.y = B.y;
    C_.y = C.y;
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
  resultRect.pos.x = (maxX - minX) / 2 + minX;
  resultRect.pos.y = (maxY - minY) / 2 + minY;
  return resultRect;
}
void gavrilova::Triangle::move(point_t p) {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  A_.x += difX;
  A_.y += difY;
  B_.x += difX;
  B_.y += difY;
  C_.x += difX;
  C_.y += difY;

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
  point_t center =  getFrameRect().pos;
  A_.x = center.x - (center.x - A_.x) * k;
  A_.y = center.y - (center.y - A_.y) * k;
  B_.x = center.x - (center.x - B_.x) * k;
  B_.y = center.y - (center.y - B_.y) * k;
  C_.x = center.x - (center.x - C_.x) * k;
  C_.y = center.y - (center.y - C_.y) * k;
}
/* gavrilova::point_t gavrilova::Triangle::getCenter() {
  double cX = (A_.x + B_.x + C_.x) / 3;
  double cY = (A_.y + B_.y + C_.y) / 3;
  return {cX, cY};
}
 */
