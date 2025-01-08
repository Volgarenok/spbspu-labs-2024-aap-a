#include "composite-shape.hpp"
#include "base-types.hpp"
#include "unified_shapes.hpp"
#include <stdexcept>

zakirov::CompositeShape::CompositeShape(point_t center, double radius)
{
  constexpr size_t possible_quantity = 1000;
  center_ = center;
  radius_ = radius;
  double in_radius = 0.1;
  double ex_radius = 0.2;
  while ((radius - in_radius) / (ex_radius - in_radius) > possible_quantity)
  {
    ex_radius += 0.1; 
  }

  ring_thickness_ = ex_radius - in_radius;
  ex_radius_ = in_radius;
  ring_quantity_ = 0;
  zakirov::Shape * shapes[possible_quantity] = {};
  while (ex_radius_ < radius_)
  {
    this->push_back(shapes);
  }

  shapes_ = shapes;
}

double zakirov::CompositeShape::getArea() const
{
  double total_area = 0.0;
  for (size_t i = 0; i < ring_quantity_; ++i)
  {
    total_area += shapes_[i]->getArea();
  }

  return total_area;
}

zakirov::rectangle_t zakirov::CompositeShape::getFrameRect() const
{
  return shapes_[ring_quantity_ - 1]->getFrameRect();
}

void zakirov::CompositeShape::move(point_t target)
{
  for (size_t i = 0; i < ring_quantity_; ++i)
  {
    shapes_[i]->move(target);
  }
}

void zakirov::CompositeShape::move(double bias_x, double bias_y)
{
  for (size_t i = 0; i < ring_quantity_; ++i)
  {
    shapes_[i]->move(bias_x, bias_y);
  }
}

void zakirov::CompositeShape::scale(double k)
{
  for (size_t i = 0; i < ring_quantity_; ++i)
  {
    shapes_[i]->scale(k);
  }
}

void zakirov::CompositeShape::push_back(Shape ** shape)
{
  shapes_[ring_quantity_] = zakirov::make_ring(center_.x, center_.y, ex_radius_, ex_radius_ + ring_thickness_);
  ++ring_quantity_;
  ex_radius_ += ring_thickness_;
}

void zakirov::CompositeShape::pop_back()
{
  if(!this->empty())
  {
    --ring_quantity_;
    shapes_[ring_quantity_]->~Shape();
  }
}

zakirov::Shape * zakirov::CompositeShape::at(size_t id)
{
  if (id < ring_quantity_)
  {
    return shapes_[id];
  }
  else
  {
    throw std::out_of_range("Incorrect id");
  }
}

zakirov::Shape * zakirov::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}

bool zakirov::CompositeShape::empty()
{
  if (ring_quantity_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

size_t zakirov::CompositeShape::size()
{
  return ring_quantity_;
}
