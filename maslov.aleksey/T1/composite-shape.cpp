#include "composite-shape.hpp"
#include <utility>

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
  if (this != &rhs)
  {
  }
  return *this;
}
maslov::CompositeShape & maslov::CompositeShape::operator=(CompositeShape && rhs)
{
  if (this != &rhs)
  {
  }
  return *this;
}
maslov::CompositeShape::~CompositeShape()
{}
void maslov::CompositeShape::push_back(Shape * shp)
{}
void maslov::CompositeShape::pop_back()
{}
maslov::Shape * maslov::CompositeShape::at(size_t id)
{}
maslov::Shape * maslov::CompositeShape::operator[](size_t id)
{}
bool maslov::CompositeShape::empty()
{}
size_t maslov::CompositeShape::size()
{}
double maslov::CompositeShape::getArea() const
{}
maslov::rectangle_t maslov::CompositeShape::getFrameRect() const
{}
void maslov::CompositeShape::move(point_t s)
{}
void maslov::CompositeShape::move(double dx, double dy)
{}
void maslov::CompositeShape::scale(double k)
{}