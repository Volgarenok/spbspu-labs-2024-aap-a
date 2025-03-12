#include "composite-shape.hpp"
#include <cmath>
#include <cstddef>
#include <stdexcept>
void kiselev::CompositeShape::clear(size_t size) noexcept
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
void kiselev::CompositeShape::swap(CompositeShape& cmp) noexcept
{
  std::swap(shapes_, cmp.shapes_);
  std::swap(capacity_, cmp.capacity_);
  std::swap(realSize_, cmp.realSize_);
}
void kiselev::CompositeShape::resize(size_t size)
{
  CompositeShape newCmp(size);
  for (size_t i = 0; i < realSize_; ++i, newCmp.realSize_++)
  {
    newCmp.shapes_[i] = shapes_[i]->clone();
  }
  swap(newCmp);
}
kiselev::CompositeShape::CompositeShape(size_t cap):
  capacity_(cap),
  realSize_(0),
  shapes_(new Shape*[capacity_])
{}
kiselev::CompositeShape::CompositeShape(const CompositeShape& cmp):
  capacity_(cmp.capacity_),
  realSize_(cmp.realSize_),
  shapes_(new Shape*[capacity_])
{
  size_t i = 0;
  try
  {
    for (; i < capacity_; ++i)
    {
      shapes_[i] = cmp[i]->clone();
    }
  }
  catch (const std::bad_alloc&)
  {
    clear(i);
    throw;
  }
}
kiselev::CompositeShape::CompositeShape(CompositeShape&& cmp) noexcept:
  capacity_(cmp.capacity_),
  realSize_(cmp.realSize_),
  shapes_(cmp.shapes_)
{
  cmp.shapes_ = nullptr;
  cmp.realSize_ = 0;
  cmp.capacity_ = 0;
}
kiselev::CompositeShape& kiselev::CompositeShape::operator=(const CompositeShape& cmp)
{
  CompositeShape cpy(cmp);
  swap(cpy);
  return *this;
}
kiselev::CompositeShape& kiselev::CompositeShape::operator=(CompositeShape&& cmp) noexcept
{
  clear(realSize_);
  shapes_ = cmp.shapes_;
  capacity_ = cmp.capacity_;
  realSize_ = cmp.realSize_;
  cmp.shapes_ = nullptr;
  cmp.realSize_ = 0;
  cmp.capacity_ = 0;
  return *this;
}
void kiselev::CompositeShape::pushBack(Shape* shp)
{
  if (realSize_ >= capacity_)
  {
    const size_t newCapacity = capacity_ * 2 + 1;
    resize(newCapacity);
  }
  shapes_[realSize_++] = shp;
}
void kiselev::CompositeShape::popBack()
{
  if (realSize_ == 0)
  {
    throw std::out_of_range("No shapes");
  }
  delete shapes_[realSize_];
  realSize_--;
}
const kiselev::Shape* kiselev::CompositeShape::at(size_t id) const
{
  if (id >= realSize_)
  {
    throw std::out_of_range("Index bigger than realSize");
  }
  return shapes_[id];
}
kiselev::Shape* kiselev::CompositeShape::at(size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).at(id));
}
const kiselev::Shape* kiselev::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}
kiselev::Shape* kiselev::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).operator[](id));
}
bool kiselev::CompositeShape::empty() const noexcept
{
  return realSize_ == 0;
}
size_t kiselev::CompositeShape::size() const noexcept
{
  return realSize_;
}
double kiselev::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < realSize_; ++i)
  {
    sum += shapes_[i]->getArea();
  }
  return sum;
}
kiselev::rectangle_t kiselev::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("There are no figures");
  }
  double leftX = 0;
  double leftY = 0;
  double rightX = 0;
  double rightY = 0;
  for (size_t i = 0; i < realSize_; ++i)
  {
    const double width = shapes_[i]->getFrameRect().width;
    const double height = shapes_[i]->getFrameRect().height;
    point_t centre = shapes_[i]->getFrameRect().pos;
    leftX = std::fmin(leftX, centre.x - width / 2);
    leftY = std::fmin(leftY, centre.y - height / 2);
    rightX = std::fmax(rightX, centre.x + width / 2);
    rightY = std::fmax(rightY, centre.y + height / 2);
  }
  return { rightX - leftX, rightY - leftY, { (rightX + leftX) / 2, (rightY + leftY) / 2 } };
}
void kiselev::CompositeShape::move(point_t a)
{
  const double moveForX = a.x - getFrameRect().pos.x;
  const double moveForY = a.y - getFrameRect().pos.y;
  move(moveForX, moveForY);
}
void kiselev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < realSize_; ++i)
  {
    shapes_[i]->move(dx, dy);
  }
}
void kiselev::CompositeShape::scale(double k, point_t scale)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scaling coefficent");
  }
  for (size_t i = 0; i < realSize_; ++i)
  {
    point_t beforeScale = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(scale);
    point_t afterScale = shapes_[i]->getFrameRect().pos;
    point_t vector = { (afterScale.x - beforeScale.x) * k, (afterScale.y - beforeScale.y) * k };
    shapes_[i]->scale(k);
    shapes_[i]->move(-vector.x, -vector.y);
  }
}
void kiselev::CompositeShape::scale(double k)
{
  point_t pScale = getFrameRect().pos;
  scale(k, pScale);
}
kiselev::CompositeShape::~CompositeShape()
{
  clear(realSize_);
}
kiselev::CompositeShape* kiselev::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}
