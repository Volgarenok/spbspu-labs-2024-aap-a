#include "compositeShape.hpp"
#include <cmath>
#include "output.hpp"
#include "shape.hpp"
void karnauhova::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < count_shapes_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

karnauhova::CompositeShape::CompositeShape(size_t count):
  count_shapes_(0),
  size_(count),
  shapes_(new Shape*[size_])
{}

karnauhova::CompositeShape::CompositeShape(const CompositeShape& other):
  count_shapes_(other.count_shapes_),
  size_(other.size_),
  shapes_(new Shape*[size_])
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i] = other.shapes_[i]->clone();
  }
}

karnauhova::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  count_shapes_(other.count_shapes_),
  size_(other.size_),
  shapes_(other.shapes_)
{
  other.count_shapes_ = 0;
  other.size_ = 0;
  other.shapes_ = nullptr;
}

karnauhova::CompositeShape::~CompositeShape()
{
  clear();
  count_shapes_ = 0;
  size_ = 0;
}

void karnauhova::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(count_shapes_, other.count_shapes_);
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

karnauhova::CompositeShape& karnauhova::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape cs(other);
  if (&other != this)
  {
    swap(cs);
  }
  return *this;
}

karnauhova::CompositeShape& karnauhova::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (std::addressof(other) != this)
  {
    clear();
    swap(other);
    other.count_shapes_ = 0;
    other.size_ = 0;
  }
  return *this;
}

void karnauhova::CompositeShape::expans(size_t new_size)
{
  Shape** new_shaps = new Shape*[new_size];
  for (size_t i = 0; i < size_; i++)
  {
    new_shaps[i] = shapes_[i];
  }
  delete[] shapes_;
  shapes_ = new_shaps;
  size_ = new_size;
}

void karnauhova::CompositeShape::push_back(Shape* shp)
{
  if (count_shapes_ >= size_)
  {
    expans(size_ + 10);
  }
  shapes_[count_shapes_++] = shp;
}

void karnauhova::CompositeShape::pop_back()
{
  if (size_ == 0)
  {
    throw std::out_of_range("CompositeShape empty");
  }
  delete shapes_[--count_shapes_];
}

karnauhova::Shape* karnauhova::CompositeShape::at(size_t id) const
{
  if (id >= count_shapes_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

karnauhova::Shape* karnauhova::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

bool karnauhova::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}

size_t karnauhova::CompositeShape::size() const noexcept
{
  return count_shapes_;
}

double karnauhova::CompositeShape::getArea() const noexcept
{
  double s = 0;
  for (size_t i = 0; i < count_shapes_; i++)
  {
    s += shapes_[i]->getArea();
  }
  return s;
}

karnauhova::rectangle_t karnauhova::CompositeShape::getFrameRect() const
{
  rectangle_t rect;
  double min_x = shapes_[0]->getFrameRect().pos.x - shapes_[0]->getFrameRect().width / 2;
  double max_x = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().width / 2;
  double min_y = shapes_[0]->getFrameRect().pos.y - shapes_[0]->getFrameRect().height / 2;
  double max_y = shapes_[0]->getFrameRect().pos.y + shapes_[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < count_shapes_; i++)
  {
    rectangle_t rectangl = shapes_[i]->getFrameRect();
    min_x = std::fmin(min_x, rectangl.pos.x - (rectangl.width / 2));
    min_y = std::fmin(min_y, rectangl.pos.y - (rectangl.height / 2));
    max_x = std::fmax(max_x, rectangl.pos.x + (rectangl.width / 2));
    max_y = std::fmax(max_y, rectangl.pos.y + (rectangl.height / 2));
  }
  rect.width = max_x - min_x;
  rect.height = max_y - min_y;
  rect.pos.x = min_x + (rect.width / 2);
  rect.pos.y = min_y + (rect.height / 2);
  return rect;
}

void karnauhova::CompositeShape::move(const point_t& t) noexcept
{
  point_t centr = getFrameRect().pos;
  double x = t.x - centr.x;
  double y = t.y - centr.y;
  move(x, y);
}

void karnauhova::CompositeShape::move(double x, double y) noexcept
{
  for (size_t i = 0; i < count_shapes_; i++) {
    shapes_[i]->move(x, y);
  }
}

void karnauhova::CompositeShape::scale(double k)
{
  point_t t = getFrameRect().pos;
  for (size_t i = 0; i < count_shapes_; i++)
  {
    scale_point(*shapes_[i], t, k);
  }
}

