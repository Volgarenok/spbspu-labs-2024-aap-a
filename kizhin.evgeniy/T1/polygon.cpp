#include "polygon.hpp"
#include <cassert>
#include <stdexcept>

namespace kizhin {
  void copy(const point_t*, const point_t*, point_t*);
  bool hasDuplicates(const point_t*, const point_t*);
  size_t countElement(const point_t*, const point_t*, const point_t);
}

kizhin::Polygon::Polygon(const point_t* values, size_t size) :
  vertices_(new point_t[size]), size_(size)
{
  assert(values && size);
  if (size < 3 || hasDuplicates(values, values + size)) {
    delete[] vertices_;
    throw std::logic_error("Failed to construct polygon");
  }
  copy(values, values + size, vertices_);
  computeFrameRect();
  computeCenter();
}

kizhin::Polygon::~Polygon()
{
  delete[] vertices_;
}

double kizhin::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i) {
    const point_t& current = vertices_[i];
    const point_t& next = vertices_[(i + 1) % size_];
    area += current.x * next.y - next.x * current.y;
  }
  return std::abs(area) / 2.0;
}

kizhin::rectangle_t kizhin::Polygon::getFrameRect() const
{
  return frameRect_;
}

void kizhin::Polygon::move(double dx, double dy)
{
  for (point_t* vertex = vertices_; vertex != vertices_ + size_; ++vertex) {
    vertex->x += dx;
    vertex->y += dy;
  }
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
  computeCenter();
}

void kizhin::Polygon::move(const point_t& newPos)
{
  const double dx = newPos.x - center_.x;
  const double dy = newPos.y - center_.y;
  move(dx, dy);
}

void kizhin::Polygon::scale(double scaleFactor)
{
  assert(scaleFactor > 0);
  for (point_t* vertex = vertices_; vertex != vertices_ + size_; ++vertex) {
    vertex->x = center_.x + scaleFactor * (vertex->x - center_.x);
    vertex->y = center_.y + scaleFactor * (vertex->y - center_.y);
  }
  computeCenter();
  computeFrameRect();
}

void kizhin::Polygon::computeFrameRect()
{
  double xMinCord = vertices_[0].x;
  double xMaxCord = vertices_[0].x;
  double yMinCord = vertices_[0].y;
  double yMaxCord = vertices_[0].y;
  for (point_t* vertex = vertices_; vertex != vertices_ + size_; ++vertex) {
    xMinCord = std::min(vertex->x, xMinCord);
    xMaxCord = std::max(vertex->x, xMaxCord);
    yMinCord = std::min(vertex->y, yMinCord);
    yMaxCord = std::max(vertex->y, yMaxCord);
  }
  const double width = xMaxCord - xMinCord;
  const double height = yMaxCord - yMinCord;
  const point_t pos = { (xMinCord + xMaxCord) / 2, (yMinCord + yMaxCord) / 2 };
  frameRect_ = { width, height, pos };
}

void kizhin::Polygon::computeCenter()
{
  double xCord = 0;
  double yCord = 0;
  for (point_t* vertex = vertices_; vertex != vertices_ + size_; ++vertex) {
    xCord += vertex->x;
    yCord += vertex->y;
  }
  xCord /= size_;
  yCord /= size_;
  center_ = { xCord, yCord };
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
