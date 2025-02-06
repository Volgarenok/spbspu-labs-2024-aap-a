#include "polygon.hpp"
#include "shapeManip.hpp"

gavrilova::Polygon::Polygon(size_t nPoints, const point_t* verteces):
  size_(0),
  triangles_(nullptr)
{
  if (nPoints < 3) {
    throw std::logic_error("Polygon must have at least 3 vertices.");
  }
  triangles_ = new Triangle*[nPoints - 2];
  for (size_t i = 0; i < (nPoints - 2); ++i) {
    try {
      triangles_[i] = new Triangle(verteces[0], verteces[i + 1], verteces[i + 2]);
      ++size_;
    } catch (const std::bad_alloc&) {
      clear();
      throw;
    }
  }
}

gavrilova::Polygon::Polygon(const Polygon& other):
  size_(other.size_),
  triangles_(nullptr)
{
  triangles_ = new Triangle*[other.size_];
  for (size_t i = 0; i < size_; ++i) {
    triangles_[i] = other.triangles_[i];
  }
}

gavrilova::Polygon::~Polygon()
{
  clear();
}

double gavrilova::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i) {
    area += triangles_[i]->getArea();
  }
  return area;
}
gavrilova::rectangle_t gavrilova::Polygon::getFrameRect() const
{
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

void gavrilova::Polygon::move(const point_t& p)
{
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}
void gavrilova::Polygon::move(double difX, double difY)
{
  for (size_t i = 0; i < size_; ++i) {
    triangles_[i]->move(difX, difY);
  }
}
void gavrilova::Polygon::scaleWithoutCheck(double k) noexcept
{
  point_t center =  getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i) {
    scaleShapeWithoutCheck(*triangles_[i], center, k);
  }
}
gavrilova::Shape* gavrilova::Polygon::clone() const
{
  return new Polygon(*this);
}

void gavrilova::Polygon::clear() noexcept
{
  for (size_t i = 0; i < size_; ++i) {
    delete triangles_[i];
  }
  delete[] triangles_;
}
