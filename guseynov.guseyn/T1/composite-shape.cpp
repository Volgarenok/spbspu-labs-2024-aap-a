#include "composite-shape.hpp"

#include <limits>
#include <cmath>

#include "Shapes-utils.hpp"

guseynov::CompositeShape::CompositeShape():
  size_(0)
{}
guseynov::CompositeShape::CompositeShape(const CompositeShape & rhs):
  size_(rhs.size_)
{
  try
  {
    cloneArray(rhs);
  }
  catch (const std::bad_alloc &)
  {
    destroyShapes(*this);
    throw;
  }
}
guseynov::CompositeShape::CompositeShape(CompositeShape && rhs) noexcept:
  size_(rhs.size_)
{
  fillArrayAndDeleteRhs(rhs);
  rhs.size_ = 0;
}
guseynov::CompositeShape & guseynov::CompositeShape::operator=(const CompositeShape & rhs)
{
  if (this != std::addressof(rhs))
  {
    CompositeShape copy{rhs};
    swap(copy);
  }
  return *this;
}
guseynov::CompositeShape & guseynov::CompositeShape::operator=(CompositeShape && rhs) noexcept
{
  if (this != std::addressof(rhs))
  {
    destroyShapes(*this);
    size_ = rhs.size_;
    fillArrayAndDeleteRhs(rhs);
    rhs.size_ = 0;
  }
  return *this;
}
guseynov::CompositeShape::~CompositeShape()
{
  destroyShapes(*this);
}
void guseynov::CompositeShape::push_back(Shape * shp)
{
  if (size_ + 1 > 10000)
  {
    throw std::out_of_range("Composite shape out of bounds");
  }
  shapeArray_[size_++] = shp;
}
void guseynov::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::out_of_range("Composite shape is empty");
  }
  delete shapeArray_[--size_];
}
guseynov::Shape * guseynov::CompositeShape::at(size_t id)
{
  return const_cast< Shape * >(const_cast< const CompositeShape * >(this)->at(id));
}
const guseynov::Shape * guseynov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapeArray_[id];
}
guseynov::Shape * guseynov::CompositeShape::operator[](size_t id)
{
  return const_cast< Shape * >(const_cast< const CompositeShape * >(this)->operator[](id));
}
const guseynov::Shape * guseynov::CompositeShape::operator[](size_t id) const
{
  return shapeArray_[id];
}
bool guseynov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t guseynov::CompositeShape::size() const noexcept
{
  return size_;
}
double guseynov::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    sum += shapeArray_[i]->getArea();
  }
  return sum;
}
guseynov::rectangle_t guseynov::CompositeShape::getFrameRect() const
{
  double maxX = std::numeric_limits< double >::min();
  double minX = std::numeric_limits< double >::max();
  double maxY = std::numeric_limits< double >::min();
  double minY = std::numeric_limits< double >::max();
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t shape = shapeArray_[i]->getFrameRect();
    point_t center = shape.pos;
    double semiHeight = shape.height / 2.0;
    double semiWidth = shape.width / 2.0;
    minX = std::min(minX, center.x - semiWidth);
    maxX = std::max(maxX, center.x + semiWidth);
    minY = std::min(minY, center.y - semiHeight);
    maxY = std::max(maxY, center.y + semiHeight);
  }
  double centerX = (minX + maxX) / 2.0;
  double centerY = (minY + maxY) / 2.0;
  double width = maxX - minX;
  double height = maxY - minY;
  return {width, height, {centerX, centerY}};
}
void guseynov::CompositeShape::move(point_t s)
{
  point_t center = getFrameRect().pos;
  double dx = s.x - center.x;
  double dy = s.y - center.y;
  move(dx, dy);
}
void guseynov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapeArray_[i]->move(dx, dy);
  }
}
void guseynov::CompositeShape::scaleWithoutCheck(double k)
{
  point_t centerComposite =  getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    point_t centerShape = shapeArray_[i]->getFrameRect().pos;
    double dx = (centerShape.x - centerComposite.x) * (k - 1);
    double dy = (centerShape.y - centerComposite.y) * (k - 1);
    shapeArray_[i]->move(dx, dy);
    shapeArray_[i]->scaleWithoutCheck(k);
  }
}
void guseynov::CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
  scaleWithoutCheck(k);
}
void guseynov::CompositeShape::cloneArray(const CompositeShape & rhs)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArray_[i] = rhs.shapeArray_[i]->clone();
  }
}
void guseynov::CompositeShape::fillArrayAndDeleteRhs(CompositeShape & rhs)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArray_[i] = rhs.shapeArray_[i];
    rhs.shapeArray_[i] = nullptr;
  }
}
void guseynov::CompositeShape::swap(CompositeShape & rhs) noexcept
{
  std::swap(size_, rhs.size_);
  for (size_t i = 0; i < std::max(size_, rhs.size_); i++)
  {
    std::swap(shapeArray_[i], rhs.shapeArray_[i]);
  }
}
