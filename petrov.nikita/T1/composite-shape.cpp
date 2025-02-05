#include "composite-shape.hpp"
#include <cmath>
#include <stdexcept>
#include "geometric_calculations.hpp"
#include "scale_isotropically_and_output_data.hpp"

namespace
{
  void deleteShapes(petrov::Shape ** ptr_shapes, size_t number_of_shapes);

  void deleteShapes(petrov::Shape ** ptr_shapes, size_t number_of_shapes)
  {
    for (size_t i = 0; i < number_of_shapes; i++)
    {
      delete ptr_shapes[i];
    }
  }
}

petrov::CompositeShape::CompositeShape():
  capacity_(0),
  size_of_vector_(0),
  shapes_vector_(nullptr)
{}

petrov::CompositeShape::CompositeShape(const CompositeShape & rhs):
  capacity_(rhs.capacity_),
  size_of_vector_(rhs.size_of_vector_),
  shapes_vector_(new Shape * [capacity_])
{
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
    deleteShapes(shapes_vector_, created);
    throw;
  }
}

petrov::CompositeShape::CompositeShape(CompositeShape && rhs) noexcept:
  capacity_(rhs.capacity_),
  size_of_vector_(rhs.size_of_vector_),
  shapes_vector_(rhs.shapes_vector_)
{
  rhs.shapes_vector_ = nullptr;
}

petrov::CompositeShape::~CompositeShape()
{
  deleteShapes(shapes_vector_, size_of_vector_);
  delete[] shapes_vector_;
}

petrov::CompositeShape & petrov::CompositeShape::operator=(const CompositeShape & rhs)
{
  CompositeShape cpy(rhs);
  this->swap(cpy);
  return *this;
}

petrov::CompositeShape & petrov::CompositeShape::operator=(CompositeShape && rhs) noexcept
{
  shapes_vector_ = rhs.shapes_vector_;
  capacity_ = rhs.capacity_;
  size_of_vector_ = rhs.size_of_vector_;
  return *this;
}

void petrov::CompositeShape::swap(CompositeShape & rhs) noexcept
{
  std::swap(capacity_, rhs.capacity_);
  std::swap(size_of_vector_, rhs.size_of_vector_);
  std::swap(shapes_vector_, rhs.shapes_vector_);
}

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
  return getFrameRectByOtherShapes(shapes_vector_, size_of_vector_);
}

void petrov::CompositeShape::move(const petrov::point_t & concrete_point)
{
  point_t pos = getFrameRect().pos;
  double dx = concrete_point.x - pos.x;
  double dy = concrete_point.y - pos.y;
  this->move(dx, dy);
}

void petrov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    shapes_vector_[i]->move(dx, dy);
  }
}

void petrov::CompositeShape::scale(double k)
{
  point_t scale_point = getFrameRect().pos;
  scaleIsotropicallyAndOutputData(scale_point, k, *this);
}

void petrov::CompositeShape::push_back(Shape * shp)
{
  if (capacity_ == 0)
  {
    capacity_ = 5;
    shapes_vector_ = new Shape * [capacity_];
    shapes_vector_[size_of_vector_++] = shp;
  }
  else if (capacity_ - 1 ==  size_of_vector_)
  {
    Shape ** temp = new Shape * [capacity_ *= 2];
    for (size_t i = 0; i < size_of_vector_; i++)
    {
      temp[i] = shapes_vector_[i];
    }
    delete[] shapes_vector_;
    shapes_vector_ = temp;
    shapes_vector_[size_of_vector_++] = shp;
  }
  else
  {
    shapes_vector_[size_of_vector_++] = shp;
  }
}

void petrov::CompositeShape::pop_back() noexcept
{
  delete shapes_vector_[--size_of_vector_];
  shapes_vector_[size_of_vector_] = nullptr;
}

petrov::Shape * petrov::CompositeShape::at(size_t id)
{
  return const_cast< Shape * >(static_cast< const CompositeShape * >(this)->at(id));
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
  return const_cast< Shape * >(static_cast< const CompositeShape * >(this)->operator[](id));
}

const petrov::Shape * petrov::CompositeShape::operator[](size_t id) const
{
  return shapes_vector_[id];
}

bool petrov::CompositeShape::empty() const noexcept
{
  return !size_of_vector_;
}

size_t petrov::CompositeShape::size() const noexcept
{
  return size_of_vector_;
}
