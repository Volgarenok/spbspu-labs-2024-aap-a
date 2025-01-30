#include "composite-shape.hpp"
#include <cstring>
#include <stdexcept>
#include "unified_shapes.hpp"

zakirov::CompositeShape::CompositeShape() :
  shapes_quantity_(0)
{
}

zakirov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    shapes_[i]->~Shape();
  }
}

double zakirov::CompositeShape::getArea()
{
  return get_total_area(shapes_, shapes_quantity_);
}

zakirov::rectangle_t zakirov::CompositeShape::getFrameRect()
{
  if (!empty())
  {
    throw std::logic_error("ERROR: empty array");
  }

  point_t min_p = {shapes_[0]->getFrameRect().pos.x, shapes_[0]->getFrameRect().pos.y};
  point_t max_p = min_p;
  for (size_t i = 1; i < shapes_quantity_; ++i)
  {
    point_t real_p = shapes_[i]->getFrameRect().pos;
    min_p = (min_p.x >= real_p.x && min_p.y >= real_p.y) ? real_p : min_p;
    max_p = (max_p.x <= real_p.x && max_p.y <= max_p.y) ? real_p : max_p;
  }

  return {max_p.x - min_p.x, max_p.y - min_p.y, get_middle(min_p, max_p)};
}

void zakirov::CompositeShape::move(point_t target)
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    shapes_[i]->move(target);
  }
}

void zakirov::CompositeShape::move(double bias_x, double bias_y)
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    shapes_[i]->move(bias_x, bias_y);
  }
}

void zakirov::CompositeShape::scale(double k)
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    shapes_[i]->scale(k);
  }
}

void zakirov::CompositeShape::push_back(Shape * shape)
{
  shapes_[shapes_quantity_++] = shape;
}

void zakirov::CompositeShape::pop_back()
{
  if (!empty())
  {
    throw std::logic_error("ERROR: empty array");
  }

  shapes_[--shapes_quantity_]->~Shape();
}

zakirov::Shape * zakirov::CompositeShape::at(size_t id)
{
  if (id >= shapes_quantity_)
  {
    throw std::invalid_argument("ERROR: id is greater, than size of array");
  }

  return shapes_[id];
}

zakirov::Shape * zakirov::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}

bool zakirov::CompositeShape::empty()
{
  if (shapes_quantity_ != 0)
  {
    return 1;
  }

  return 0;
}

size_t zakirov::CompositeShape::size()
{
  return shapes_quantity_;
}
