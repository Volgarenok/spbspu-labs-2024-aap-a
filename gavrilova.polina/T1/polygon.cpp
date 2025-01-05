#include "polygon.hpp"
#include <cmath>
#include <iostream>
#include "base-types.hpp"

gavrilova::Polygon::Polygon(size_t nPoints, point_t * verteces):
  size_(nPoints - 2),
  triangles_(nullptr)
{
  if (nPoints < 3) {
    throw std::logic_error("Polygon must have at least 3 vertices.");
  }
  triangles_ = new gavrilova::Triangle*[size_];
  for (size_t i = 1; i < nPoints - 1; ++i) {
    triangles_[i] = new gavrilova::Triangle(verteces[0], verteces[i + 1], verteces[i + 2]);
  }
}
gavrilova::Polygon::Polygon(const Polygon& other):
  size_(other.size_),
  triangles_(nullptr)
{
  triangles_ = new gavrilova::Triangle*[size_];
  for (size_t i = 0; i < size_; ++i) {
    triangles_[i] = other.triangles_[i];
  }
}

gavrilova::Polygon::~Polygon() {
  for (size_t i = 0; i < size_; ++i) {
    delete triangles_[i];
  }
  delete[] triangles_;
}

double gavrilova::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i) {
    area += triangles_[i]->getArea();
  }
  return area;
}
gavrilova::rectangle_t gavrilova::Polygon::getFrameRect() const {
  double minX = triangles_[0]->getFrameRect().pos.x - triangles_[0]->getFrameRect().width / 2;
  double maxX = triangles_[0]->getFrameRect().pos.x + triangles_[0]->getFrameRect().width / 2;
  double minY = triangles_[0]->getFrameRect().pos.y - triangles_[0]->getFrameRect().height / 2;
  double maxY = triangles_[0]->getFrameRect().pos.y + triangles_[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < size_; ++i) {
    rectangle_t rect = triangles_[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
  }

  rectangle_t frameRect = {maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 }};
  return frameRect;
  }
void gavrilova::Polygon::move(point_t p) {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Polygon::move(double difX, double difY) {
  for (size_t i = 0; i < size_; ++i) {
    triangles_[i]->move(difX, difY);
  }
}
void gavrilova::Polygon::scale(double k) {
 for (size_t i = 0; i < size_; ++i) {
    triangles_[i]->scale(k);
  }
}
gavrilova::Shape* gavrilova::Polygon::clone() const {
  return new Polygon(*this);
}
