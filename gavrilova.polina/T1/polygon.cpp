#include "polygon.hpp"
#include "shapeManip.hpp"

namespace {
  bool hasSameVerteces(const gavrilova::point_t* verteces, size_t size)
  {
    for (size_t i = 0; i < (size - 1); ++i) {
      for (size_t j = (i + 1); j < size; ++j) {
        if (verteces[i].x == verteces[j].x && verteces[i].y == verteces[j].y) {
          return true;
        }
      }
    }
    return false;
  }
}


gavrilova::Polygon::Polygon(size_t nPoints, const point_t* verteces):
  size_(nPoints - 2),
  triangles_(new Shape*[size_])
{
  if (nPoints < 3) {
    throw std::logic_error("Polygon must have at least 3 vertices.");
  }
  if (!nPoints || ::hasSameVerteces(verteces, nPoints)) {
    throw std::logic_error("Errors in polygon parametrs");
  }
  size_t cur_size = 0;
  for (size_t i = 0; i < size_; ++i) {
    try {
      triangles_[i] = new Triangle(verteces[0], verteces[i + 1], verteces[i + 2]);
      ++cur_size;
    } catch (const std::bad_alloc&) {
      size_ = cur_size;
      clear();
      throw;
    }
  }
}

gavrilova::Polygon::Polygon(const Polygon& other):
  size_(other.size_),
  triangles_(new Shape*[other.size_])
{
  size_t cur_size = 0;
  for (size_t i = 0; i < size_; ++i) {
    try {
      triangles_[i] = other.triangles_[i]->clone();
      ++cur_size;
    } catch (const std::bad_alloc&) {
      size_ = cur_size;
      clear();
      throw;
    }
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
  if (!size_) {
    throw std::logic_error("Composite shape is empty.");
  }
  return getFrameRectForShapes(triangles_, size_);
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
  point_t center = getFrameRect().pos;
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
  clearShapes(triangles_, size_);
}
