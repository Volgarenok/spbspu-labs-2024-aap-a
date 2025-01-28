#include "composite-shape.hpp"
#include "base-types.hpp"
#include "scale_isotropically_and_output_data.hpp"
#include <cmath>
#include <stdexcept>
double petrov::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    area += shapes_vector_[i]->getArea();
  }
  return area;
}

petrov::rectangle_t petrov::CompositeShape::getFrameRect() const
{
  rectangle_t shape_frame_rect = shapes_vector_[0]->getFrameRect();
  double xmin = shape_frame_rect.pos.x - shape_frame_rect.width / 2;
  double ymin = shape_frame_rect.pos.y - shape_frame_rect.height / 2;
  double xmax = shape_frame_rect.pos.x + shape_frame_rect.width / 2;
  double ymax = shape_frame_rect.pos.y + shape_frame_rect.height / 2;
  for (size_t i = 1; i < size_of_vector_; i++)
  {
    shape_frame_rect = shapes_vector_[i]->getFrameRect();
    double temp_xmin = shape_frame_rect.pos.x - shape_frame_rect.width / 2;
    double temp_ymin = shape_frame_rect.pos.y - shape_frame_rect.height / 2;
    double temp_xmax = shape_frame_rect.pos.x + shape_frame_rect.width / 2;
    double temp_ymax = shape_frame_rect.pos.y + shape_frame_rect.height / 2;
    temp_xmin < xmin ? xmin = temp_xmin : xmin = xmin;
    temp_ymin < ymin ? ymin = temp_ymin : ymin = ymin;
    temp_xmax > xmax ? xmax = temp_xmax : xmax = xmax;
    temp_ymax > ymax ? ymax = temp_ymax : ymax = ymax;
  }
  rectangle_t composite_shape_frame_rect = {};
  composite_shape_frame_rect.width = std::abs(xmax - xmin);
  composite_shape_frame_rect.height = std::abs(ymax - ymin);
  composite_shape_frame_rect.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
  return composite_shape_frame_rect;
}

void petrov::CompositeShape::move(petrov::point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  this->move(dx, dy);
}

void petrov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    shapes_vector_[i]->move(dx, dy);
  }
}

void petrov::CompositeShape::scale()
{
  rectangle_t frame_rect = getFrameRect();
  point_t scale_point = frame_rect.pos;
  double scale_value = 2.0;
  scaleIsotropicallyAndOutputData(scale_point, scale_value, shapes_vector_, size_of_vector_);
}

void petrov::CompositeShape::push_back(Shape * shp)
{
  if (capacity_ == 0)
  {
    capacity_ = 5;
    shapes_vector_ = new Shape * [capacity_];
    shapes_vector_[size_of_vector_++] = shp;
  }
  else if (capacity_ ==  ++size_of_vector_)
  {
    Shape ** temp = new Shape * [capacity_ *= 2];
    for (size_t i = 0; i < size_of_vector_ - 1; i++)
    {
      temp[i] = shapes_vector_[i];
    }
    delete[] shapes_vector_;
    shapes_vector_ = temp;
    shapes_vector_[size_of_vector_] = shp;
  }
  else
  {
    shapes_vector_[size_of_vector_] = shp;
  }
}

void petrov::CompositeShape::pop_back() noexcept
{
  delete[] shapes_vector_[size_of_vector_];
  shapes_vector_[size_of_vector_--] = nullptr;
}

petrov::Shape * petrov::CompositeShape::at(size_t id)
{
  if (id < size_of_vector_)
  {
    return shapes_vector_[id];
  }
  else
  {
    throw std::out_of_range("The element does not exist at this position");
  }
}

const petrov::Shape * petrov::CompositeShape::at(size_t id) const
{
  if (id < size_of_vector_)
  {
    return shapes_vector_[id];
  }
  else
  {
    throw std::out_of_range("The element does not exist at this position");
  }
}

petrov::Shape * petrov::CompositeShape::operator[](size_t id)
{
  return shapes_vector_[id];
}

const petrov::Shape * petrov::CompositeShape::operator[](size_t id) const
{
  return shapes_vector_[id];
}

bool petrov::CompositeShape::empty() const noexcept
{
  if (!size_of_vector_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

size_t petrov::CompositeShape::size() const noexcept
{
  return size_of_vector_;
}

petrov::CompositeShape::CompositeShape(CompositeShape & rhs):
  capacity_(rhs.capacity_),
  size_of_vector_(rhs.size_of_vector_)
{
  shapes_vector_ = new Shape * [capacity_];
  size_t created = 0;
  try
  {
    for (size_t i = 0; i < size_of_vector_; i++)
    {
      shapes_vector_[i] = rhs.shapes_vector_[i]->clone();
      created++;
    }
  }
  catch (const std::bad_alloc & e)
  {
    for (size_t i = 0; i < created; i++)
    {
      delete[] shapes_vector_[i];
    }
    throw;
  }
}

petrov::CompositeShape & petrov::CompositeShape::operator=(CompositeShape & rhs)
{
  Shape ** temp = new Shape * [rhs.size_of_vector_];
  size_t created = 0;
  try
  {
    for (size_t i = 0; i < size_of_vector_; i++)
    {
      temp[i] = rhs.shapes_vector_[i]->clone();
      created++;
    }
  }
  catch (const std::bad_alloc & e)
  {
    for (size_t i = 0; i < created; i++)
    {
      delete[] temp[i];
    }
    delete[] temp;
    throw;
  }
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    delete[] shapes_vector_[i];
  }
  delete[] shapes_vector_;
  shapes_vector_ = temp;
  capacity_ = rhs.capacity_;
  size_of_vector_ = rhs.size_of_vector_;
  return *this;
}

petrov::CompositeShape::CompositeShape(CompositeShape && rhs) noexcept:
  capacity_(rhs.capacity_),
  size_of_vector_(rhs.size_of_vector_),
  shapes_vector_(rhs.shapes_vector_)
{
  rhs.shapes_vector_ = nullptr;
}

petrov::CompositeShape & petrov::CompositeShape::operator=(CompositeShape && rhs) noexcept
{
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    delete[] shapes_vector_[i];
  }
  delete[] shapes_vector_;
  shapes_vector_ = rhs.shapes_vector_;
  capacity_ = rhs.capacity_;
  size_of_vector_ = rhs.size_of_vector_;
  return *this;
}

petrov::CompositeShape::~CompositeShape()
{
  delete[] shapes_vector_;
}
