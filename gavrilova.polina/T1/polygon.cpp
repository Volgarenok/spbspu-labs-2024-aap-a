#include "polygon.hpp"
#include <iostream>
#include "shapeManip.hpp"

gavrilova::Polygon::Polygon(size_t nPoints, point_t* verteces):
  size_(0),
  triangles_(nullptr)
{
  if (nPoints < 3) {
    throw std::logic_error("Polygon must have at least 3 vertices.");
  }
  size_ = nPoints - 2;
  triangles_ = new gavrilova::Triangle*[size_];
  size_t created = 0;
  for (size_t i = 0; i < size_; ++i) {
    try{
      triangles_[i] = new gavrilova::Triangle(verteces[0], verteces[i + 1], verteces[i + 2]);
      ++created;
    } catch (const std::bad_alloc&) {
      clear(created);
      throw;
    }
  }
}
gavrilova::Polygon::Polygon(const Polygon& other):
  size_(other.size_),
  triangles_(nullptr)
{
  triangles_ = new gavrilova::Triangle*[size_];
  size_t created = 0;
  for (size_t i = 0; i < size_; ++i) {
    try{
      triangles_[i] = new gavrilova::Triangle(*other.triangles_[i]);
      ++created;
    } catch (const std::bad_alloc&) {
      clear(created);
      throw;
    }
  }
}

gavrilova::Polygon::~Polygon() {
  clear(size_);
}

double gavrilova::Polygon::getArea() const noexcept {
  double area = 0;
  for (size_t i = 0; i < size_; ++i) {
    area += triangles_[i]->getArea();
  }
  return area;
}
gavrilova::rectangle_t gavrilova::Polygon::getFrameRect() const noexcept {
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
  return {maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 }};
}

void gavrilova::Polygon::move(const point_t& p) noexcept {
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Polygon::move(double difX, double difY) noexcept {
  for (size_t i = 0; i < size_; ++i) {
    triangles_[i]->move(difX, difY);
  }
}
void gavrilova::Polygon::scale_without_check(double k) {
  point_t center =  getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i) {
    scaleShape(*triangles_[i], center, k);
  }
}
gavrilova::Shape* gavrilova::Polygon::clone() const {
  return new Polygon(*this);
}

void gavrilova::Polygon::clear(size_t created) {
  for (size_t i = 0; i < created; ++i) {
    delete triangles_[i];
  }
  delete[] triangles_;
}
