#include "composite-shape.hpp"
#include <cmath>
#include <stdexcept>
void kiselev::CompositeShape::clear(size_t size) noexcept
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
kiselev::CompositeShape::CompositeShape(size_t cap):
  capacity(cap),
  realSize(0),
  shapes(new Shape*[capacity])
{}
kiselev::CompositeShape::CompositeShape(const CompositeShape& cmp):
  capacity(cmp.capacity),
  realSize(cmp.realSize),
  shapes(new Shape*[capacity])
{
  size_t i = 0;
  try
  {
    for (; i < capacity; ++i)
    {
      shapes[i] = cmp[i]->clone();
    }
  }
  catch (const std::bad_alloc&)
  {
    clear(i);
    throw;
  }
}
kiselev::CompositeShape::CompositeShape(CompositeShape&& cmp) noexcept:
  capacity(cmp.capacity),
  realSize(cmp.realSize),
  shapes(cmp.shapes)
{
  cmp.shapes = nullptr;
  realSize = 0;
}
kiselev::CompositeShape& kiselev::CompositeShape::operator=(const CompositeShape& cmp)
{
  CompositeShape cpy(cmp);
  std::swap(shapes, cpy.shapes);
  std::swap(capacity, cpy.capacity);
  std::swap(realSize, cpy.realSize);
  return *this;
}
kiselev::CompositeShape& kiselev::CompositeShape::operator=(CompositeShape&& cmp) noexcept
{
  clear(realSize);
  shapes = cmp.shapes;
  capacity = cmp.capacity;
  realSize = cmp.realSize;
  cmp.shapes = nullptr;
  cmp.realSize = 0;
  return *this;
}
void kiselev::CompositeShape::pushBack(Shape* shp)
{
  if (realSize >= capacity)
  {
    throw std::out_of_range("Exceeded capacity");
  }
  shapes[realSize++] = shp;
}
void kiselev::CompositeShape::popBack()
{
  if (realSize == 0)
  {
    throw std::out_of_range("No shapes");
  }
  delete shapes[realSize];
  realSize--;
}
const kiselev::Shape* kiselev::CompositeShape::at(size_t id) const
{
  if (id >= realSize)
  {
    throw std::out_of_range("Index bigger than realSize");
  }
  return shapes[id];
}
kiselev::Shape* kiselev::CompositeShape::at(size_t id)
{
  return const_cast<Shape*>(static_cast<const CompositeShape&>(*this).at(id));
}
const kiselev::Shape* kiselev::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes[id];
}
kiselev::Shape* kiselev::CompositeShape::operator[](size_t id) noexcept
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
  move(moveForX, moveForY);
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
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scaling coefficent");
  }
  for (size_t i = 0; i < realSize; ++i)
  {
    point_t beforeScale = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scale);
    point_t afterScale = shapes[i]->getFrameRect().pos;
    point_t vector = { (afterScale.x - beforeScale.x) * k, (afterScale.y - beforeScale.y) * k };
    shapes[i]->scale(k);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void kiselev::CompositeShape::scale(double k)
{
  point_t pScale = getFrameRect().pos;
  scale(k, pScale);
}
kiselev::CompositeShape::~CompositeShape()
{
  clear(realSize);
}
kiselev::CompositeShape kiselev::CompositeShape::clone() const
{
  return CompositeShape(*this);
}
