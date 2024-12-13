#include "polygon.hpp"
#include <cassert>
#include <stdexcept>
#include "point_utils.hpp"

namespace kizhin {
  void copy(const point_t*, const point_t*, point_t*);
  bool hasDuplicates(const point_t*, const point_t*);
  size_t countElement(const point_t*, const point_t*, const point_t);
}

kizhin::Polygon::Polygon(const Polygon& rhs) :
  vertices_(new point_t[rhs.size_]), size_(rhs.size_), center_(rhs.center_), frame_(rhs.frame_)
{
  copy(rhs.vertices_, rhs.vertices_ + size_, vertices_);
}

kizhin::Polygon::Polygon(Polygon&& rhs) noexcept :
  vertices_(rhs.vertices_), size_(rhs.size_), center_(rhs.center_), frame_(rhs.frame_)
{
  rhs.vertices_ = nullptr;
}

kizhin::Polygon::Polygon(const point_t* values, size_t size) :
  vertices_(new point_t[size]), size_(size)
{
  assert(values);
  if (size < 3 || hasDuplicates(values, values + size)) {
    delete[] vertices_;
    throw std::logic_error("Invalid Points For Polygon Construction");
  }
  copy(values, values + size, vertices_);
  computeFrameRect();
  computeCenter();
}

kizhin::Polygon::~Polygon()
{
  delete[] vertices_;
}

kizhin::Polygon& kizhin::Polygon::operator=(const Polygon& rhs)
{
  Polygon tmp = rhs;
  swap(tmp);
  return *this;
}

kizhin::Polygon& kizhin::Polygon::operator=(Polygon&& rhs) noexcept
{
  delete[] vertices_;
  swap(rhs);
  return *this;
}

kizhin::rectangle_t kizhin::Polygon::getFrameRect() const
{
  return frame_;
}

double kizhin::Polygon::getArea() const
{
  double area = 0.0;
  for (point_t *i = vertices_, *end = vertices_ + size_; i != end; ++i) {
    const point_t& current = *i;
    const point_t& next = (i + 1 == end) ? *vertices_ : *(i + 1);
    area += current.x * next.y - next.x * current.y;
  }
  return std::abs(area) / 2.0;
}

void kizhin::Polygon::move(double dx, double dy)
{
  for (point_t* i = vertices_; i != vertices_ + size_; ++i) {
    *i += { dx, dy };
  }
  frame_.pos += { dx, dy };
  center_ += { dx, dy };
}

void kizhin::Polygon::move(const point_t& newPos)
{
  const double dx = newPos.x - center_.x;
  const double dy = newPos.y - center_.y;
  move(dx, dy);
}

void kizhin::Polygon::scale(double scaleFactor)
{
  assert(scaleFactor > 0.0);
  for (point_t* i = vertices_; i != vertices_ + size_; ++i) {
    i->x = center_.x + scaleFactor * (i->x - center_.x);
    i->y = center_.y + scaleFactor * (i->y - center_.y);
  }
  computeCenter();
  computeFrameRect();
}

void kizhin::Polygon::computeFrameRect()
{
  double* edgeCords = computeEdgeCords(vertices_, size_);
  const double width = edgeCords[1] - edgeCords[0];
  const double height = edgeCords[3] - edgeCords[2];
  const point_t pos = {
    (edgeCords[0] + edgeCords[1]) / 2.0,
    (edgeCords[2] + edgeCords[3]) / 2.0,
  };
  frame_ = { width, height, pos };
  delete[] edgeCords;
}

void kizhin::Polygon::computeCenter()
{
  point_t sum { 0.0, 0.0 };
  for (point_t* i = vertices_; i != vertices_ + size_; ++i) {
    sum += *i;
  }
  center_ = { sum.x / size_, sum.y / size_ };
}

void kizhin::Polygon::swap(Polygon& rhs) noexcept
{
  std::swap(vertices_, rhs.vertices_);
  std::swap(size_, rhs.size_);
  std::swap(center_, rhs.center_);
  std::swap(frame_, rhs.frame_);
}

void kizhin::copy(const point_t* first, const point_t* last, point_t* result)
{
  for (; first != last; ++first, ++result) {
    *result = *first;
  }
}

bool kizhin::hasDuplicates(const point_t* begin, const point_t* end)
{
  for (const point_t* i = begin; i != end; ++i) {
    if (countElement(begin, end, *i) > 1) {
      return true;
    }
  }
  return false;
}

size_t kizhin::countElement(const point_t* begin, const point_t* end, const point_t val)
{
  size_t count = 0;
  for (; begin != end; ++begin) {
    count += begin->x == val.x && begin->y == val.y;
  }
  return count;
}

