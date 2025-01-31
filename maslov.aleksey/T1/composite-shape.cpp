#include "composite-shape.hpp"
#include <limits>
#include <cmath>
#include "shapeManipulator.hpp"

maslov::CompositeShape::CompositeShape():
  size_(0)
{}
maslov::CompositeShape::CompositeShape(const CompositeShape & rhs):
  size_(rhs.size_)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArray_[i] = rhs.shapeArray_[i]->clone();
  }
}
maslov::CompositeShape::CompositeShape(CompositeShape && rhs):
  size_(rhs.size_)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapeArray_[i] = rhs.shapeArray_[i];
    rhs.shapeArray_[i] = nullptr;
  }
  rhs.size_ = 0;
}
maslov::CompositeShape & maslov::CompositeShape::operator=(const CompositeShape & rhs)
{
  if (this != std::addressof(rhs))
  {
    destroyShapes(*this);
    size_ = rhs.size_;
    for (size_t i = 0; i < size_; i++)
    {
      shapeArray_[i] = rhs.shapeArray_[i]->clone();
    }
  }
  return *this;
}
maslov::CompositeShape & maslov::CompositeShape::operator=(CompositeShape && rhs)
{
  if (this != std::addressof(rhs))
  {
    destroyShapes(*this);
    size_ = rhs.size_;
    for (size_t i = 0; i < size_; i++)
    {
      shapeArray_[i] = rhs.shapeArray_[i];
      rhs.shapeArray_[i] = nullptr;
    }
  }
  return *this;
}
maslov::CompositeShape::~CompositeShape()
{
  destroyShapes(*this);
}
void maslov::CompositeShape::push_back(Shape * shp)
{
  shapeArray_[size_++] = shp;
}
void maslov::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::out_of_range("Composite shape is empty");
  }
  delete shapeArray_[--size_];
}
maslov::Shape * maslov::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapeArray_[id];
}
const maslov::Shape * maslov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapeArray_[id];
}
maslov::Shape * maslov::CompositeShape::operator[](size_t id)
{
  return shapeArray_[id];
}
const maslov::Shape * maslov::CompositeShape::operator[](size_t id) const
{
  return shapeArray_[id];
}
bool maslov::CompositeShape::empty() const
{
  return size_ == 0;
}
size_t maslov::CompositeShape::size() const
{
  return size_;
}
double maslov::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    sum += shapeArray_[i]->getArea();
  }
  return sum;
}
maslov::rectangle_t maslov::CompositeShape::getFrameRect() const
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
void maslov::CompositeShape::move(point_t s)
{
  point_t center = getFrameRect().pos;
  double dx = s.x - center.x;
  double dy = s.y - center.y;
  move(dx, dy);
}
void maslov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapeArray_[i]->move(dx, dy);
  }
}
void maslov::CompositeShape::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Incorrect scale factor");
  }
  point_t centerComposite =  getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    point_t centerShape = shapeArray_[i]->getFrameRect().pos;
    double dx = (centerShape.x - centerComposite.x) * (k - 1);
    double dy = (centerShape.y - centerComposite.y) * (k - 1);
    shapeArray_[i]->move(dx, dy);
    shapeArray_[i]->scale(k);
  }
}
