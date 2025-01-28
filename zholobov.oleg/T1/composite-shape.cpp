#include "composite-shape.hpp"

zholobov::CompositeShape::CompositeShape()
{
}

zholobov::CompositeShape::CompositeShape(const CompositeShape& other)
{
}

zholobov::CompositeShape::CompositeShape(CompositeShape&& other)
{
}

zholobov::CompositeShape::~CompositeShape()
{
}

void zholobov::CompositeShape::push_back(Shape* shp)
{
}

void zholobov::CompositeShape::pop_back()
{
}

zholobov::Shape* zholobov::CompositeShape::at(size_t id) const
{
  return nullptr;
}

zholobov::Shape* zholobov::CompositeShape::operator[](size_t id) const
{
  return nullptr;
}

bool zholobov::CompositeShape::empty() const
{
  return false;
}

size_t zholobov::CompositeShape::size() const
{
  return size_t();
}

double zholobov::CompositeShape::getArea() const
{
  return 0.0;
}

zholobov::rectangle_t zholobov::CompositeShape::getFrameRect() const
{
  return rectangle_t();
}

void zholobov::CompositeShape::move(point_t p)
{
}

void zholobov::CompositeShape::move(double dx, double dy)
{
}

void zholobov::CompositeShape::scale(double k)
{
}
