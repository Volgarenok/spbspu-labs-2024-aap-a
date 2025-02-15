#include "composite-shape.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "base-types.hpp"
#include "getShapeInfo.hpp"

const double minDouble = std::numeric_limits<double>::lowest();
const double maxDouble = std::numeric_limits<double>::max();

dribas::CompositeShape::CompositeShape():
  size_(0)
{
  for (size_t i = 0; i < 10000; i++) {
    shapes_[i] = nullptr;
  }
}

dribas::CompositeShape::CompositeShape(CompositeShape&& shp) noexcept:
  size_(shp.size_)
{
  for (size_t i = 0; i < shp.size_; i++) {
    shapes_[i] = shp.shapes_[i];
    shp.shapes_[i] = nullptr;
  }
  shp.size_ = 0;
}

dribas::CompositeShape& dribas::CompositeShape::operator=(const CompositeShape& shp)
{
  if (this != &shp) {
    for (size_t i = 0; i < size_; ++i) {
      delete shapes_[i];
    }
    size_ = shp.size_;
    for (size_t i = 0; i < size_; ++i) {
      shapes_[i] = shp.shapes_[i]->clone();
    }
    for (size_t i = size_; i < 10000; ++i) {
      shapes_[i] = nullptr;
    }
  }
  return *this;
}

dribas::CompositeShape& dribas::CompositeShape::operator=(CompositeShape&& shp) noexcept
{
  if (this != &shp) {
    for (size_t i = 0; i < size_; ++i) {
      delete shapes_[i];
    }
    size_ = shp.size_;
    for (size_t i = 0; i < size_; ++i) {
      shapes_[i] = shp.shapes_[i];
      shp.shapes_[i] = nullptr;
    }
    shp.size_ = 0;
  }
  return *this;
}

dribas::CompositeShape::CompositeShape(const CompositeShape& shp):
  size_(shp.size_)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i] = shp.shapes_[i]->clone();
  }
}
void dribas::CompositeShape::push_back(Shape * shp)
{
  if (size_ + 1 > 9999) {
    std::logic_error("MEMROY IS FULL");
  }
  shapes_[++size_] = shp;
}
void dribas::CompositeShape::pop_back()
{
  if (size_ == 0) {
    std::logic_error("MEMORY IS EMPTY");
  }
  delete shapes_[--size_];
}

dribas::Shape* dribas::CompositeShape::at(size_t id)
{
  if (id > size_) {
    throw std::logic_error("ID OUT OF RANGE\n");
  }
  return shapes_[id];
}
dribas::Shape* dribas::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}

bool dribas::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t dribas::CompositeShape::size() const noexcept
{
  return size_;
}
double dribas::CompositeShape::getArea() const noexcept
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}
dribas::rectangle_t dribas::CompositeShape::getFrameRect() const
{
  double minY = minDouble;
  double minX = minDouble;
  double maxX = maxDouble;
  double maxY = maxDouble;

  for (size_t i = 0; i < size_; i++) {
    rectangle_t frem = shapes_[size_]->getFrameRect();
    minX = std::min(minX, frem.pos.x - (frem.width / 2.0f));
    minY = std::min(minY, frem.pos.y - (frem.height / 2.0f));
    maxX = std::max(maxX, frem.pos.x + (frem.width / 2.0f));
    maxY = std::max(maxY, frem.pos.y + (frem.height / 2.0f));
  }
  point_t center = { minX + (maxX - minX) / 2.0f, minY + (maxY - minY) / 2.0f };

  return rectangle_t{std::abs(maxX - minX), std::abs(maxY - minY), center };
}
void dribas::CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(x, y);
  }
}
void dribas::CompositeShape::move(point_t point)
{
  point_t center = getFrameRect().pos;
  move(point.x - center.x, point.y - center.y);
}
void dribas::CompositeShape::scale(double ratio)
{
  point_t center = this->getFrameRect().pos;
  scalingAll(shapes_, size_, center, ratio);
}
