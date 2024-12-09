#include "polygon.hpp"
#include "base-types.hpp"
#include <cmath>
#include <iostream>

gavrilova::Polygon::Triangle(size_t size, point_t * verteces)
{
  //не забыть про центр
}
double gavrilova::Polygon::getArea() const
{
  double S = 0;
  double sum1 = 0, sum2 = 0;
  for (size_t i = 0; i < (size_ - 1); ++i) {
    sum1 += (verteces_[i].x * verteces_[i+1].y);
    sum2 += (verteces_[i].y * verteces_[i+1].x);
  }
  sum1 += (verteces_[size_ - 1].x * verteces_[0].y)
  sum2 += (verteces_[size_ - 1].y * verteces_[0].x)
  S = (sum1 - sum2) / 2;
  return S;
}
gavrilova::rectangle_t gavrilova::Polygon::getFrameRect() const {
  rectangle_t resultRect;
  double minX = verteces_[0].x, maxX = verteces_[0].x, minY = verteces_[0].y,  maxY = verteces_[0].y;
  for (size_t i = 1; i < size_; ++i) {
    minX = std::min(minX, verteces_[i].x);
    minY = std::min(minY, verteces_[i].y);
    maxX = std::max(maxX, verteces_[i].x);
    maxY = std::max(maxY, verteces_[i].y);
  }
  resultRect.height = maxY - minY;
  resultRect.width = maxX- minX;
  resultRect.pos.x = (maxX- minX)/2;
  resultRect.pos.y = (maxY - minY)/2;
  return resultRect;
}
void gavrilova::Polygon::move(point_t p) {
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
