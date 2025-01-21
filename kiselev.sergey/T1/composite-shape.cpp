#include "composite-shape.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <stdexcept>
void kiselev::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < realSize; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
kiselev::CompositeShape::CompositeShape(size_t cap):
 capacity(cap),
 realSize(0),
 shapes(new Shape *[capacity])
{
}
kiselev::CompositeShape::CompositeShape(const CompositeShape & cmp):
 capacity(cmp.capacity),
 realSize(cmp.realSize),
 shapes(new Shape *[capacity])
{
  if (shapes)
  {
    for (size_t i = 0; i < capacity; ++i)
    {
      *shapes[i] = *cmp[i];
    }
  }
}
kiselev::CompositeShape::CompositeShape(CompositeShape && cmp) noexcept:
 capacity(cmp.capacity),
 realSize(cmp.realSize),
 shapes(cmp.shapes)
{
  cmp.shapes = nullptr;
  realSize = 0;
}
kiselev::CompositeShape & kiselev::CompositeShape::operator=(const CompositeShape & cmp)
{
  CompositeShape cpy(cmp);
  std::swap(shapes, cpy.shapes);
  std::swap(capacity, cpy.capacity);
  std::swap(realSize, cpy.realSize);
  return *this;
}
kiselev::CompositeShape & kiselev::CompositeShape::operator=(CompositeShape && cmp) noexcept
{
  clear();
  shapes = cmp.shapes;
  capacity = cmp.capacity;
  realSize = cmp.realSize;
  cmp.shapes = nullptr;
  cmp.realSize = 0;
  return *this;
}
void kiselev::CompositeShape::push_back(Shape * shp)
{
  if (realSize >= capacity)
  {
    throw std::out_of_range("Exceeded capacity");
  }
  shapes[realSize++] = shp;
}
void kiselev::CompositeShape::pop_back()
{
  if (realSize == 0)
  {
    throw std::out_of_range("No shapes");
  }
  delete shapes[realSize];
  realSize--;
}
kiselev::Shape * kiselev::CompositeShape::at(size_t id) const
{
  if (id >= realSize)
  {
    throw std::out_of_range("Index bigger than realSize");
  }
  return shapes[id];
}
kiselev::Shape * kiselev::CompositeShape::at(size_t id)
{
  if (id >= realSize)
  {
    throw std::out_of_range("Index bigger than realSize");
  }
  return shapes[id];
}
kiselev::Shape * kiselev::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes[id];
}
kiselev::Shape * kiselev::CompositeShape::operator[](size_t id) noexcept
{
  return shapes[id];
}
bool kiselev::CompositeShape::empty() const noexcept
{
  return realSize == 0;
}
size_t kiselev::CompositeShape::size() const noexcept
{
  return realSize;
}
double kiselev::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < realSize; ++i)
  {
    sum += shapes[i]->getArea();
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
  for (size_t i = 0; i < realSize; ++i)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    point_t centre = shapes[i]->getFrameRect().pos;
    leftX = std::fmin(leftX, centre.x - width / 2);
    leftY = std::fmin(leftY, centre.y - height / 2);
    rightX = std::fmax(rightX, centre.x + width / 2);
    rightY = std::fmax(rightY, centre.y + height / 2);
  }
  return { rightX - leftX, rightY - leftY, { (rightX + leftX) / 2, (rightY + leftY) / 2 } };
}
void kiselev::CompositeShape::move(point_t a)
{
  double moveForX = a.x - getFrameRect().pos.x;
  double moveForY = a.y - getFrameRect().pos.y;
  this->move(moveForX, moveForY);
}
void kiselev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < realSize; ++i)
  {
    shapes[i]->move(dx, dy);
  }
}
void kiselev::CompositeShape::scale(double k, point_t scale)
{
  for (size_t i = 0; i < realSize; ++i)
  {
    kiselev::point_t beforeScale = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scale);
    kiselev::point_t afterScale = shapes[i]->getFrameRect().pos;
    kiselev::point_t vector = { (afterScale.x - beforeScale.x) * k, (afterScale.y - beforeScale.y) * k };
    shapes[i]->scale(k);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void kiselev::CompositeShape::scale(double k)
{
  point_t scale = getFrameRect().pos;
  this->scale(k, scale);
}
kiselev::CompositeShape::~CompositeShape()
{
  clear();
}
kiselev::CompositeShape* kiselev::CompositeShape::clone() const
{
  CompositeShape* clone = new CompositeShape(capacity);
  Shape* shape = nullptr;
  try
  {
    for (size_t i = 0; i < realSize; ++i)
    {
      shape = shapes[i]->clone();
      clone->push_back(shape);
    }
  }
  catch (...)
  {
    delete shape;
    delete clone;
    throw;
  }
  return clone;
}
