#include "composite-shape.hpp"
#include <stdexcept>
#include "shape.hpp"
#include <iostream>
alymova::CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(new Shape*[capacity_])
{}
alymova::CompositeShape::CompositeShape(const CompositeShape& comp_shape):
  size_(comp_shape.size_),
  capacity_(comp_shape.capacity_),
  shapes_(new Shape*[capacity_]())
{
  copyArray(comp_shape.shapes_);
  std::cout << "Constructor coping\n";
}
alymova::CompositeShape::CompositeShape(CompositeShape&& comp_shape):
  size_(comp_shape.size_),
  capacity_(comp_shape.capacity_),
  shapes_(new Shape*[capacity_]())
{
  copyArray(comp_shape.shapes_);
  std::cout << "Contructor moving\n";
}
alymova::CompositeShape::~CompositeShape()
{
  clear(shapes_);
}
alymova::CompositeShape& alymova::CompositeShape::operator=(const CompositeShape& comp_shape)
{
  try
  {
    if (this != &comp_shape)
    {
      CompositeShape copy{comp_shape};
      //capacity_ = comp_shape.capacity_;
      //size_ = comp_shape.size_;
      clear(shapes_);
      shapes_ = new Shape*[comp_shape.capacity_];
      swap(copy);
    }
    std::cout << "Operator coping\n";
    return *this;
  }
  catch (const std::bad_alloc& e)
  {
    clear(shapes_);
    throw std::runtime_error("Copying assigment error");
  }
}
alymova::CompositeShape& alymova::CompositeShape::operator=(CompositeShape&& comp_shape)
{
  try
  {
    //CompositeShape move{std::move(comp_shape)};
    //capacity_ = comp_shape.capacity_;
    //size_ = comp_shape.size_;
    clear(shapes_);
    shapes_ = new Shape*[comp_shape.capacity_];
    swap(comp_shape);
    std::cout << "Operator moving\n";
    return *this;
  }
  catch (const std::bad_alloc& e)
  {
    clear(shapes_);
    throw;
    //throw std::runtime_error("Moving assigment error");
  }
}
alymova::Shape* alymova::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}
const alymova::Shape* alymova::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}
double alymova::CompositeShape::getArea() const noexcept
{
  double area_sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area_sum += shapes_[i]->getArea();
  }
  return area_sum;
}
alymova::rectangle_t alymova::CompositeShape::getFrameRect() const noexcept
{
  rectangle_t max_frame_rect = getMaxFrameRect();
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t rect = {shapes_[i]->getFrameRect()};
    point_t low_left = getLowLeftFrameRect(rect);
    point_t upp_right = getUppRightFrameRect(rect);
    changeFrameRect(max_frame_rect, low_left.x, low_left.y, upp_right.x, upp_right.y);
  }
  return max_frame_rect;
}
void alymova::CompositeShape::move(const point_t& point) noexcept
{
  point_t pos = getFrameRect().pos;
  double shift_x = point.x - pos.x;
  double shift_y = point.y - pos.y;
  move(shift_x, shift_y);
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
  checkRatioScale(ratio);
  unsafeScale(ratio);
}
void alymova::CompositeShape::unsafeScale(double ratio) noexcept
{
  point_t pos = getFrameRect().pos;
  alymova::unsafeScale(*this, pos, ratio);
}
void alymova::CompositeShape::push_back(Shape* shp)
{
  if (size_ == capacity_)
  {
    int ratio = 2;
    Shape** shapes_new = new Shape*[capacity_ * ratio]();
    for (size_t i = 0; i < size_; i++)
    {
      shapes_new[i] = shapes_[i];
    }
    clear(shapes_);
    shapes_ = shapes_new;
    capacity_ *= ratio;
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
bool alymova::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t alymova::CompositeShape::size() const noexcept
{
  return size_;
}
void alymova::CompositeShape::copyArray(const Shape* const* other_shapes)
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
    shapes_[i] = other_shapes[i]->clone();
  }
}
void alymova::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  for (size_t i = 0; i < size_; i++)
  {
    std::swap(shapes_[i], other.shapes_[i]);
    //shapes_[i] = other[i];
    //other.do_null(i);
  }
}
void alymova::CompositeShape::do_null(size_t id) noexcept
{
  shapes_[id] = nullptr;
}
void alymova::CompositeShape::clear(Shape** shapes) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
