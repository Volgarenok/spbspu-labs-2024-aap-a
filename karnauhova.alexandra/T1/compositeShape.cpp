#include "compositeShape.hpp"
#include <cmath>
#include <stdexcept>
#include "output.hpp"
#include "shape.hpp"
#include "point.hpp"
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
  try
  {
    for (size_t i = 0; i < size_; i++)
    {
      shapes_[i] = other.shapes_[i]->clone();
    }
  }
  catch (const std::exception& e)
  {
    clear();
    throw;
  }
}

karnauhova::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  count_shapes_(other.count_shapes_),
  size_(other.size_),
  shapes_(other.shapes_)
{
  other.shapes_ = nullptr;
}

karnauhova::CompositeShape::~CompositeShape()
{
  clear();
}

void karnauhova::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(count_shapes_, other.count_shapes_);
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

karnauhova::CompositeShape& karnauhova::CompositeShape::operator=(const CompositeShape& other)
{
  if (&other != this)
  {
    CompositeShape cs(other);
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
  }
  return *this;
}

void karnauhova::CompositeShape::expanse(size_t new_size)
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
    expanse(size_ + 10);
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

const karnauhova::Shape* karnauhova::CompositeShape::at(size_t id) const
{
  if (id >= count_shapes_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

karnauhova::Shape* karnauhova::CompositeShape::at(size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->at(id));
}

karnauhova::Shape* karnauhova::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->operator[](id));
}

const karnauhova::Shape* karnauhova::CompositeShape::operator[](size_t id) const noexcept
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
  return frameRect(shapes_, count_shapes_);
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
    scale_point(shapes_[i], t, k);
  }
}

void karnauhova::CompositeShape::scale_with_check(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect coef");
  }
  scale(k);
}

karnauhova::CompositeShape* karnauhova::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

