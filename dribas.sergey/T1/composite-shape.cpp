#include "composite-shape.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>
#include "base-types.hpp"

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
  if (std::addressof(shp) != this) {
    clear();
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
  if (std::addressof(shp) != this) {
    clear();
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

void dribas::CompositeShape::push_back(Shape* shp)
{
  if (size_ == 100) {
    throw std::overflow_error("MEMORY IS FULL");
  } else {
    shapes_[size_++] = shp;
  }
}

void dribas::CompositeShape::pop_back()
{
  if (size_ == 0) {
    throw std::logic_error("MEMORY IS EMPTY");
  }
  delete shapes_[--size_];
}

dribas::Shape* dribas::CompositeShape::at(size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->at(id));
}

const dribas::Shape* dribas::CompositeShape::at(size_t id) const
{
  if (id > size_) {
    throw std::logic_error("ID OUT OF RANGE\n");
  }
  return shapes_[id];
}

dribas::Shape* dribas::CompositeShape::operator[](size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->operator[](id));
}

const dribas::Shape* dribas::CompositeShape::operator[](size_t id) const
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
  double minY = std::numeric_limits< double >::lowest();
  double minX = std::numeric_limits< double >::lowest();
  double maxX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::max();

  for (size_t i = 0; i < size_; i++) {
    rectangle_t frem = shapes_[size_]->getFrameRect();
    minX = std::min(minX, frem.pos.x - (frem.width / 2.0));
    minY = std::min(minY, frem.pos.y - (frem.height / 2.0));
    maxX = std::max(maxX, frem.pos.x + (frem.width / 2.0));
    maxY = std::max(maxY, frem.pos.y + (frem.height / 2.0));
  }
  point_t center = { minX + (maxX - minX) / 2.0, minY + (maxY - minY) / 2.0 };

  return rectangle_t { std::abs(maxX - minX), std::abs(maxY - minY), center };
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

void dribas::CompositeShape::scaleSilent(double ratio)
{
  point_t center = getFrameRect().pos;
  scaleWithCenter(center, ratio);
}

void dribas::CompositeShape::scaleWithCenter(point_t center, double ratio)
{
  for (size_t i = 0; i < size_; i++) {
    point_t cneter = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(center);
    point_t center2 = shapes_[i]->getFrameRect().pos;
    double diffenceX = (center2.x - cneter.x) * ratio * -1;
    double diffenceY = (center2.y - cneter.y) * ratio * -1;
    shapes_[i]->scaleSilent(ratio);
    shapes_[i]->move(diffenceX, diffenceY);
  }
}

dribas::CompositeShape::~CompositeShape()
{
  clear();
}

void dribas::CompositeShape::clear() noexcept
{
  while (!empty()) {
    pop_back();
  }
}
