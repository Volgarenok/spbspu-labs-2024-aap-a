#include "composite-shape.hpp"
#include <cstring>
#include <stdexcept>
#include "unified_shapes.hpp"
#include "base-types.hpp"

#include <iostream>
#include "ring.hpp"
zakirov::CompositeShape::CompositeShape() :
  shapes_quantity_(0)
{
}

zakirov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    clear_shapes(shapes_, shapes_quantity_);
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
  double most_top = shapes_[0]->getFrameRect().pos.y;
  double most_low = shapes_[0]->getFrameRect().pos.y;
  double most_left = shapes_[0]->getFrameRect().pos.x;
  double most_right = shapes_[0]->getFrameRect().pos.x;
  for (size_t i = 0; i < shapes_quantity_; ++i)
  {
    rectangle_t frame_rect = shapes_[i]->getFrameRect();
    double shape_top = frame_rect.height / 2.0 + frame_rect.pos.y;
    double shape_low = frame_rect.height / 2.0 - frame_rect.pos.y;
    double shape_left = frame_rect.width / 2.0 - frame_rect.pos.x;
    double shape_right = frame_rect.width / 2.0 + frame_rect.pos.x;
    most_top = most_top <= shape_top ? shape_top : most_top;
    most_low = most_low >= shape_low ? shape_low : most_low;
    most_left = most_left >= shape_left ? shape_left : most_left;
    most_right = most_right <= shape_right ? shape_right : most_right;
  }
  point_t center = get_middle({most_right, most_top}, {most_left, most_low});
  return {most_right - most_left, most_top - most_low, center};
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
  if (shape)
  {
    shapes_[shapes_quantity_] = shape;
    ++shapes_quantity_;
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

bool zakirov::CompositeShape::empty() const
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
