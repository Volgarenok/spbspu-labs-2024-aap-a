#include "polygon.hpp"
#include "base-types.hpp"
#include <cmath>
#include <iostream>

gavrilova::Polygon::Polygon(size_t size, point_t * verteces):
size_(size), verteces_(verteces)
{}

double gavrilova::Polygon::getArea() const
{
  double S = 0;
  double sum1 = 0, sum2 = 0;
  for (size_t i = 0; i < (size_ - 1); ++i) {
    sum1 += (verteces_[i].x * verteces_[i+1].y);
    sum2 += (verteces_[i].y * verteces_[i+1].x);
  }
  sum1 += (verteces_[size_ - 1].x * verteces_[0].y);
  sum2 += (verteces_[size_ - 1].y * verteces_[0].x);
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
  point_t center = getCenter();
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  for (size_t i = 1; i < size_; ++i) {
    verteces_[i].x += difX;
    verteces_[i].y += difY;
  }
}
void gavrilova::Polygon::move(double difX, double difY) {
  for (size_t i = 1; i < size_; ++i) {
    verteces_[i].x += difX;
    verteces_[i].y += difY;
  }
}
void gavrilova::Polygon::scale(double k) {
  point_t center = getCenter();
  for (size_t i = 1; i < size_; ++i) {
    verteces_[i].x = center.x - (center.x - verteces_[i].x) / 2 * k;
    verteces_[i].y = center.y - (center.y - verteces_[i].y) / 2 * k;
  }
}
gavrilova::point_t gavrilova::Polygon::getCenter() {
  double xC = 0, yC = 0;
  for (size_t i = 0; i <size_; ++i) {
    xC += verteces_[i].x;
    yC += verteces_[i].y;
  }
  xC /= size_;
  yC /= size_;
  return {xC, yC};
}