#include "composite-shape.hpp"
#include <stdexcept>
#include "shape.hpp"
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
  size_t size_now = 0;
  try
  {
    for (; size_now < size_; size_now++)
    {
      shapes_[size_now] = comp_shape[size_now]->clone();
    }
  }
  catch (const std::bad_alloc& e)
  {
    clear(size_now);
    throw;
  }
}
alymova::CompositeShape::CompositeShape(CompositeShape&& comp_shape):
  size_(comp_shape.size_),
  capacity_(comp_shape.capacity_),
  shapes_(comp_shape.shapes_)
{
  do_default(comp_shape);
}
alymova::CompositeShape::~CompositeShape()
{
  clear();
}
alymova::CompositeShape& alymova::CompositeShape::operator=(const CompositeShape& comp_shape)
{
  if (this != std::addressof(comp_shape))
  {
    CompositeShape copy{comp_shape};
    swap(copy);
  }
  return *this;
}
alymova::CompositeShape& alymova::CompositeShape::operator=(CompositeShape&& comp_shape)
{
  clear();
  size_ = comp_shape.size_;
  capacity_ = comp_shape.capacity_;
  shapes_ = comp_shape.shapes_;
  do_default(comp_shape);
  return *this;
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
    clear();
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
void alymova::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(shapes_, other.shapes_);
}
void alymova::CompositeShape::do_default(CompositeShape& comp_shape) noexcept
{
  comp_shape.size_ = 0;
  comp_shape.capacity_ = 0;
  comp_shape.shapes_ = nullptr;
}
void alymova::CompositeShape::clear() noexcept
{
  clear(size_);
}
void alymova::CompositeShape::clear(size_t size_now) noexcept
{
  for (size_t i = 0; i < size_now; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
