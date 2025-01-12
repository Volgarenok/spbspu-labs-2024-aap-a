#include "composite-shape.hpp"
#include "shape.hpp"
#include <stdexcept>
alymova::CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(nullptr),
  frame_rect_points_(nullptr)
{
  try
  {
    shapes_ = new Shape*[capacity_];
  }
  catch (const std::bad_alloc& e)
  {
    clear(shapes_);
    throw;
  }
}
alymova::CompositeShape::CompositeShape(const CompositeShape& comp_shape):
    size_(comp_shape.size_),
    capacity_(comp_shape.capacity_),
    shapes_(nullptr),
    frame_rect_points_(nullptr)
{
  bool copy_success = true;
  try
  {
    shapes_ = new Shape*[capacity_];
    for (size_t i = 0; i < capacity_; i++)
    {
        shapes_[i] = nullptr;
    }
    copyArray(comp_shape.shapes_, shapes_, copy_success);
  }
  catch (const std::bad_alloc& e)
  {
    size_ = 0;
    capacity_ = 10;
    clear(shapes_);
    throw;
  }
  if (!copy_success)
  {
    size_ = 0;
    capacity_ = 10;
    clear(shapes_);
    throw std::bad_alloc();
  }
}
alymova::CompositeShape::CompositeShape(const CompositeShape&& comp_shape) :
    size_(comp_shape.size_),
    capacity_(comp_shape.capacity_),
    shapes_(nullptr),
    frame_rect_points_(nullptr)
{
  bool copy_success = true;
  try
  {
    shapes_ = new Shape*[capacity_];
    copyArray(comp_shape.shapes_, shapes_, copy_success);
  }
  catch (const std::bad_alloc& e)
  {
    size_ = 0;
    capacity_ = 10;
    clear(shapes_);
    throw;
  }
  if (!copy_success)
  {
    size_ = 0;
    capacity_ = 10;
    clear(shapes_);
    throw std::bad_alloc();
  }
}
alymova::CompositeShape::~CompositeShape()
{
  clear(shapes_);
  delete[] frame_rect_points_;
}
alymova::CompositeShape& alymova::CompositeShape::operator=(const CompositeShape& comp_shape)
{
  if (this != &comp_shape)
  {
    bool copy_success = true;
    copyArray(comp_shape.shapes_, shapes_, copy_success);
    if (!copy_success)
    {
      throw std::bad_alloc();
    }
    size_ = comp_shape.size_;
    capacity_ = comp_shape.capacity_;
  }
  return *this;
}
alymova::CompositeShape& alymova::CompositeShape::operator=(const CompositeShape&& comp_shape)
{
  bool copy_success = true;
  copyArray(comp_shape.shapes_, shapes_, copy_success);
  if (!copy_success)
  {
    throw std::bad_alloc();
  }
  size_ = comp_shape.size_;
  capacity_ = comp_shape.capacity_;
  return *this;
}
alymova::Shape* alymova::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}
double alymova::CompositeShape::getArea() noexcept
{
  double area_sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area_sum += shapes_[i]->getArea();
  }
  return area_sum;
}
alymova::rectangle_t* alymova::CompositeShape::getFrameRect() noexcept
{
  try
  {
    frame_rect_points_ = new alymova::rectangle_t[size_];
    for (size_t i = 0; i < size_; i++)
    {
      frame_rect_points_[i] = shapes_[i]->getFrameRect();
    }
  }
  catch (const std::bad_alloc& e)
  {
    delete[] frame_rect_points_;
    return nullptr;
  }
  return frame_rect_points_;
}
void alymova::CompositeShape::move(point_t point) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(point);
  }
}
void alymova::CompositeShape::move(double shift_x, double shift_y) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(shift_x, shift_y);
  }
}
void alymova::CompositeShape::scale(double ratio)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->scale(ratio);
  }
}
void alymova::CompositeShape::unsafeScale(double ratio)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->unsafeScale(ratio);
  }
}
void alymova::CompositeShape::push_back(Shape* shp)
{
  if (size_ == capacity_)
  {
    int ratio = 2;
    capacity_ *= ratio;
    Shape** shapes_new_ = nullptr;
    bool copy_success = true;
    try
    {
      shapes_new_ = new Shape*[capacity_];
      copyArray(shapes_, shapes_new_, copy_success);
      clear(shapes_);
      shapes_ = shapes_new_;
    }
    catch (const std::bad_alloc& e)
    {
      capacity_ /= ratio;
      clear(shapes_new_);
      throw;
    }
    if (!copy_success)
    {
      capacity_ /= ratio;
      clear(shapes_new_);
      throw std::bad_alloc();
    }
  }
  shapes_[size_] = shp;
  size_++;
}
void alymova::CompositeShape::pop_back() noexcept
{
  if (size_ > 0)
  {
    delete shapes_[size_ - 1];
    size_--;
  }
}
alymova::Shape* alymova::CompositeShape::at(size_t id)
{
  if (id > (size_ - 1))
  {
    throw std::out_of_range("Incorrect index");
  }
  return shapes_[id];
}
bool alymova::CompositeShape::empty() noexcept
{
  if (size_ == 0)
  {
    return true;
  }
  return false;
}
size_t alymova::CompositeShape::size() noexcept
{
  return size_;
}
void alymova::CompositeShape::copyArray(Shape** other_shapes, Shape** shapes_new, bool& copy_success)
{
  for (size_t i = 0; i < size_; i++)
  {
    Shape* tmp = nullptr;
    try
    {
        tmp = shapes_new[i];
      //tmp = shapes_new[i]->clone();
    }
    catch (const std::bad_alloc& e)
    {
      delete tmp;
      copy_success = false;
      return;
    }
    delete shapes_new[i];
    try
    {
      shapes_new[i] = other_shapes[i]->clone();
    }
    catch (const std::bad_alloc& e)
    {
      shapes_new[i] = tmp;
      copy_success = false;
      return;
    }
  }
}
void alymova::CompositeShape::clear(Shape** shapes) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
