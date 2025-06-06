#include "composite-shape.hpp"
#include <algorithm>
#include <cmath>
#include "shapeManipulations.hpp"

namespace
{
  void cloneArray(kushekbaev::Shape** destination, kushekbaev::Shape** source, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      destination[i] = source[i]->clone();
    }
  }
}

kushekbaev::CompositeShape::CompositeShape(size_t capacity):
  array_(new Shape*[capacity]),
  capacity_(capacity),
  shapeCounter_(0)
{}

kushekbaev::CompositeShape::CompositeShape(const CompositeShape& rhs):
  array_(new Shape*[rhs.capacity_]),
  capacity_(rhs.capacity_),
  shapeCounter_(rhs.shapeCounter_)
{
  try
  {
    cloneArray(array_, rhs.array_, shapeCounter_);
  }
  catch (const std::bad_alloc&)
  {
    clear();
    throw;
  }
}

kushekbaev::CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept:
  array_(rhs.array_),
  capacity_(rhs.capacity_),
  shapeCounter_(rhs.shapeCounter_)
{
  rhs.array_ = nullptr;
  rhs.shapeCounter_ = 0;
  rhs.capacity_ = 0;
}

kushekbaev::CompositeShape::~CompositeShape()
{
  clear();
}

kushekbaev::CompositeShape& kushekbaev::CompositeShape::operator=(const CompositeShape& rhs)
{
  if (std::addressof(rhs) != this)
  {
    CompositeShape cs(rhs);
    swap(cs);
  }
  return *this;
}

kushekbaev::CompositeShape& kushekbaev::CompositeShape::operator=(CompositeShape&& rhs) noexcept
{
  if (std::addressof(rhs) != this)
  {
    clear();
    swap(rhs);
  }
  return *this;
}

const kushekbaev::Shape* kushekbaev::CompositeShape::operator[](size_t id) const noexcept
{
  return array_[id];
}

kushekbaev::Shape* kushekbaev::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).operator[](id));
}

double kushekbaev::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < shapeCounter_; i++)
  {
    area += array_[i]->getArea();
  }
  return area;
}

kushekbaev::CompositeShape* kushekbaev::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

kushekbaev::rectangle_t kushekbaev::CompositeShape::getFrameRect() const
{
  double lLX = 0;
  double lLY = 0;
  double uRX = 0;
  double uRY = 0;
  for (size_t i = 0; i < shapeCounter_; i++)
  {
    double height = array_[i]->getFrameRect().height;
    double width = array_[i]->getFrameRect().width;
    point_t scaleCoeff = array_[i]->getFrameRect().pos;
    lLX = std::fmin(lLX, scaleCoeff.x - width / 2);
    lLY = std::fmin(lLY, scaleCoeff.y - height / 2);
    uRX = std::fmax(uRX, scaleCoeff.x + width / 2);
    uRY = std::fmax(uRY, scaleCoeff.y + height / 2);
  }
  return { uRX - lLX, uRY - lLY, { (uRX + lLX) / 2, (uRY + lLY) / 2} };
}

void kushekbaev::CompositeShape::move(point_t scalePoint)
{
  double dx = scalePoint.x - getFrameRect().pos.x;
  double dy = scalePoint.y - getFrameRect().pos.y;
  move(dx, dy);
}

void kushekbaev::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < shapeCounter_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void kushekbaev::CompositeShape::scale(double scaleCoeff)
{
  point_t scalePoint = getFrameRect().pos;
  for (size_t i = 0; i < shapeCounter_; i++)
  {
    point_t before = array_[i]->getFrameRect().pos;
    array_[i]->move(scalePoint);
    point_t after = array_[i]->getFrameRect().pos;
    point_t vector = { (after.x - before.x) * scaleCoeff, (after.y - before.y) * scaleCoeff };
    array_[i]->scale(scaleCoeff);
    array_[i]->move(-vector.x, -vector.y);
  }
}

void kushekbaev::CompositeShape::push_back(Shape* shp)
{
  if (shapeCounter_ >= capacity_)
  {
    const size_t newCapacity = capacity_ * 2 + 1;
    scaleArray(newCapacity);
  }
  array_[shapeCounter_++] = shp;
}

void kushekbaev::CompositeShape::pop_back()
{
  if (shapeCounter_ == 0)
  {
    throw std::out_of_range("No compShape");
  }
  delete array_[shapeCounter_ - 1];
  shapeCounter_--;
}

const kushekbaev::Shape* kushekbaev::CompositeShape::at(size_t id) const
{
  if (id >= shapeCounter_)
  {
    throw std::out_of_range("Index bigger than realSize");
  }
  return array_[id];
}

kushekbaev::Shape* kushekbaev::CompositeShape::at(size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).at(id));
}

bool kushekbaev::CompositeShape::empty() const noexcept
{
  return (shapeCounter_ == 0);
}

size_t kushekbaev::CompositeShape::size() const noexcept
{
  return shapeCounter_;
}

void kushekbaev::CompositeShape::swap(CompositeShape& rhs)
{
  std::swap(array_, rhs.array_);
  std::swap(capacity_, rhs.capacity_);
  std::swap(shapeCounter_, rhs.shapeCounter_);
}

void kushekbaev::CompositeShape::scaleArray(size_t size)
{
  CompositeShape newArray(size);
  cloneArray(newArray.array_, array_, shapeCounter_);
  newArray.shapeCounter_ += shapeCounter_;
  swap(newArray);
}

void kushekbaev::CompositeShape::clear()
{
  for (size_t i = 0; i < shapeCounter_; ++i)
  {
    delete array_[i];
  }
  delete[] array_;
}

void kushekbaev::scaleEverything(CompositeShape *compShape, point_t scalePoint, double scaleCoeff)
{
  size_t size = compShape->size();
  for (size_t i = 0; i < size; i++)
  {
    point_t start = compShape[i].getFrameRect().pos;
    compShape[i].move(scalePoint);
    point_t end = compShape[i].getFrameRect().pos;
    point_t vector = { (end.x - start.x) * scaleCoeff, (end.y - start.y) * scaleCoeff };
    compShape[i].scale(scaleCoeff);
    compShape[i].move(-vector.x,  -vector.y);
  }
}
