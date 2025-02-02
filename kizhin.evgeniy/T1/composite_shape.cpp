#include "composite_shape.hpp"
#include <algorithm>
#include <stdexcept>
#include "shape_utils.hpp"

namespace kizhin {
  rectangle_t combineRectangles(const rectangle_t&, const rectangle_t&);
}

kizhin::CompositeShape::CompositeShape(size_t capacity):
  begin_(capacity > 0 ? new Shape*[capacity] : nullptr),
  end_(begin_),
  end_cap_(begin_ ? begin_ + capacity : begin_)
{
}

kizhin::CompositeShape::CompositeShape(const CompositeShape& rhs):
  CompositeShape(rhs.size())
{
  for (Shape* const* i = rhs.begin_; i != rhs.end_; ++i, ++end_) {
    *end_ = (*i)->clone();
  }
}

kizhin::CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept:
  begin_(rhs.begin_),
  end_(rhs.end_),
  end_cap_(rhs.end_cap_)
{
  rhs.begin_ = nullptr;
  rhs.end_ = nullptr;
  rhs.end_cap_ = nullptr;
}

kizhin::CompositeShape::~CompositeShape()
{
  clear();
}

kizhin::CompositeShape& kizhin::CompositeShape::operator=(const CompositeShape& rhs)
{
  CompositeShape tmp(rhs);
  swap(tmp);
  return *this;
}

kizhin::CompositeShape& kizhin::CompositeShape::operator=(CompositeShape&& rhs) noexcept
{
  if (this != std::addressof(rhs)) {
    clear();
    swap(rhs);
  }
  return *this;
}

kizhin::Shape* kizhin::CompositeShape::operator[](size_t index) noexcept
{
  return begin_[index];
}

const kizhin::Shape* kizhin::CompositeShape::operator[](size_t index) const noexcept
{
  return begin_[index];
}

size_t kizhin::CompositeShape::size() const noexcept
{
  return end_ - begin_;
}

bool kizhin::CompositeShape::empty() const noexcept
{
  return begin_ == end_;
}

kizhin::Shape** kizhin::CompositeShape::data() const noexcept
{
  return begin_;
}

const kizhin::Shape* kizhin::CompositeShape::at(size_t index) const
{
  if (index >= size()) {
    throw_out_of_range();
  }
  return begin_[index];
}

kizhin::Shape* kizhin::CompositeShape::at(size_t index)
{
  if (index >= size()) {
    throw_out_of_range();
  }
  return begin_[index];
}

kizhin::rectangle_t kizhin::CompositeShape::getFrameRect() const
{
  rectangle_t frame = (*begin_)->getFrameRect();
  for (const Shape* const* i = begin_ + 1; i != end_; ++i) {
    frame = combineRectangles(frame, (*i)->getFrameRect());
  }
  return frame;
}

double kizhin::CompositeShape::getArea() const
{
  double totalArea = 0.0;
  for (const Shape* const* i = begin_; i != end_; ++i) {
    totalArea += (*i)->getArea();
  }
  return totalArea;
}

kizhin::CompositeShape kizhin::CompositeShape::clone() const
{
  return CompositeShape(*this);
}

void kizhin::CompositeShape::move(const point_t& newPos)
{
  const point_t currentCenter = getFrameRect().pos;
  const double dx = newPos.x - currentCenter.x;
  const double dy = newPos.y - currentCenter.y;
  move(dx, dy);
}

void kizhin::CompositeShape::move(double dx, double dy)
{
  CompositeShape tmp(*this);
  for (Shape* const* i = tmp.begin_; i != tmp.end_; ++i) {
    (*i)->move(dx, dy);
  }
  swap(tmp);
}

void kizhin::CompositeShape::scale(double scalingFactor)
{
  if (scalingFactor <= 0) {
    throw std::logic_error("Scaling factor must be positive");
  }
  CompositeShape tmp(*this);
  const point_t center = tmp.getFrameRect().pos;
  for (Shape** i = tmp.begin_; i != tmp.end_; ++i) {
    Shape* scaled = scaleShape(*i, scalingFactor, center);
    delete *i;
    *i = scaled;
  }
  swap(tmp);
}

void kizhin::CompositeShape::push_back(Shape* shape)
{
  if (end_ == end_cap_) {
    resize(empty() ? 1 : size() * 2);
  }
  *end_ = shape;
  ++end_;
}

void kizhin::CompositeShape::pop_back()
{
  --end_;
  delete *end_;
}

void kizhin::CompositeShape::resize(size_t newCapacity)
{
  CompositeShape tmp(newCapacity);
  const size_t newSize = std::min(size(), newCapacity);
  for (Shape* const* i = begin_; i != begin_ + newSize; ++i, ++tmp.end_) {
    *tmp.end_ = (*i)->clone();
  }
  swap(tmp);
}

void kizhin::CompositeShape::swap(CompositeShape& rhs) noexcept
{
  using std::swap;
  swap(begin_, rhs.begin_);
  swap(end_, rhs.end_);
  swap(end_cap_, rhs.end_cap_);
}

void kizhin::CompositeShape::clear() noexcept
{
  for (Shape** i = begin_; i != end_; ++i) {
    delete *i;
  }
  delete[] begin_;
  begin_ = nullptr;
  end_ = nullptr;
  end_cap_ = nullptr;
}

void kizhin::CompositeShape::throw_out_of_range() const
{
  throw std::out_of_range("CompositeShape: out of range");
}

kizhin::rectangle_t kizhin::combineRectangles(const rectangle_t& rect1,
    const rectangle_t& rect2)
{
  const double rect1MinX = rect1.pos.x - rect1.width / 2;
  const double rect1MaxX = rect1.pos.x + rect1.width / 2;
  const double rect1MinY = rect1.pos.y - rect1.height / 2;
  const double rect1MaxY = rect1.pos.y + rect1.height / 2;

  const double rect2MinX = rect2.pos.x - rect2.width / 2;
  const double rect2MaxX = rect2.pos.x + rect2.width / 2;
  const double rect2MinY = rect2.pos.y - rect2.height / 2;
  const double rect2MaxY = rect2.pos.y + rect2.height / 2;

  const double minX = std::min(rect1MinX, rect2MinX);
  const double maxX = std::max(rect1MaxX, rect2MaxX);
  const double minY = std::min(rect1MinY, rect2MinY);
  const double maxY = std::max(rect1MaxY, rect2MaxY);

  const double width = maxX - minX;
  const double height = maxY - minY;
  const point_t pos = {
    (minX + maxX) / 2,
    (minY + maxY) / 2,
  };
  return { width, height, pos };
}

