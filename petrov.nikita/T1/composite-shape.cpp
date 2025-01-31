#include "composite-shape.hpp"
#include <cmath>
#include <stdexcept>
#include "scale_isotropically_and_output_data.hpp"

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
    for (size_t i = 0; i < created; i++)
    {
      delete shapes_vector_[i];
    }
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
  delete[] shapes_vector_;
}

petrov::CompositeShape & petrov::CompositeShape::operator=(const CompositeShape & rhs)
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
      delete temp[i];
    }
    delete[] temp;
    throw;
  }
  for (size_t i = 0; i < size_of_vector_; i++)
  {
    delete shapes_vector_[i];
  }
  delete[] shapes_vector_;
  shapes_vector_ = temp;
  capacity_ = rhs.capacity_;
  size_of_vector_ = rhs.size_of_vector_;
  return *this;
}

petrov::CompositeShape & petrov::CompositeShape::operator=(CompositeShape && rhs) noexcept
{
  shapes_vector_ = rhs.shapes_vector_;
  capacity_ = rhs.capacity_;
  size_of_vector_ = rhs.size_of_vector_;
  return *this;
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
  double width = xmax - xmin;
  double height = ymax - ymin;
  point_t pos = { ((xmin + xmax) / 2.0), ((ymin + ymax) / 2.0) };
  return { width, height, pos };
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
  scaleIsotropicallyAndOutputData(scale_point, k, this);
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
  return const_cast< Shape * >(const_cast < const CompositeShape * >(this)->at(id));
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
  return const_cast< Shape * >(const_cast < const CompositeShape * >(this)->operator[](id));
}

const petrov::Shape * petrov::CompositeShape::operator[](size_t id) const
{
  return shapes_vector_[id];
}

bool petrov::CompositeShape::empty() const noexcept
{
  return !size_of_vector_ ? true : false;
}

size_t petrov::CompositeShape::size() const noexcept
{
  return size_of_vector_;
}
