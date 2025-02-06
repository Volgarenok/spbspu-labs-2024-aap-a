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
  clear_shapes(shapes_, shapes_quantity_);
}

double zakirov::CompositeShape::getArea() noexcept
{
  return get_total_area(shapes_, shapes_quantity_);
}

zakirov::rectangle_t zakirov::CompositeShape::getFrameRect() const
{
  if (!empty())
  {
    throw std::logic_error("ERROR: empty composition");
  }

  double most_top = shapes_[0]->getFrameRect().pos.y;
  double most_low = shapes_[0]->getFrameRect().pos.y;
  double most_left = shapes_[0]->getFrameRect().pos.x;
  double most_right = shapes_[0]->getFrameRect().pos.x;
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    rectangle_t frame_rect = shapes_[i]->getFrameRect();
    double shape_top = frame_rect.height / 2.0 + frame_rect.pos.y;
    double shape_low = -frame_rect.height / 2.0 + frame_rect.pos.y;
    double shape_left = -frame_rect.width / 2.0 + frame_rect.pos.x;
    double shape_right = frame_rect.width / 2.0 + frame_rect.pos.x;
    most_top = std::max(most_top, shape_top);
    most_low = std::min(most_low, shape_low);
    most_left = std::min(most_left, shape_left);
    most_right = std::max(most_right, shape_right);
  }
  double height = most_top - most_low;
  double width = most_right - most_left;
  point_t center = {most_right - width / 2.0, most_top - height / 2.0};
  return {most_right - most_left, most_top - most_low, center};
}

void zakirov::CompositeShape::move(const point_t & target) noexcept
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    shapes_[i]->move(target);
  }
}

void zakirov::CompositeShape::move(double bias_x, double bias_y) noexcept
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
  if (shape)
  {
    shapes_[shapes_quantity_++] = shape;
  }
}

void zakirov::CompositeShape::pop_back()
{
  if (!empty())
  {
    throw std::logic_error("ERROR: empty array");
  }

  --shapes_quantity_;
  shapes_[shapes_quantity_]->~Shape();
  free(shapes_[shapes_quantity_]);
}

zakirov::Shape * zakirov::CompositeShape::at(size_t id) const
{
  if (id >= shapes_quantity_)
  {
    throw std::invalid_argument("ERROR: id is greater, than size of array");
  }

  return shapes_[id];
}

zakirov::Shape * zakirov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

bool zakirov::CompositeShape::empty() const noexcept
{
  return shapes_quantity_ != 0;
}

size_t zakirov::CompositeShape::size() const noexcept
{
  return shapes_quantity_;
}
