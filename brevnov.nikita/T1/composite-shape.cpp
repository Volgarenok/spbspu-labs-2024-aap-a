#include "composite-shape.hpp"
#include <utility>
#include <stdexcept>
#include <cmath>
#include "shape.hpp"

void brevnov::print_frame_coordinates(const brevnov::CompositeShape& coSh, std::ostream & out)
{
  print_frame_coordinates(coSh.shapes_, coSh.current_size_, out);
}

void brevnov::CompositeShape::clear() noexcept
{
  clearShape(shapes_, current_size_);
}

brevnov::CompositeShape::CompositeShape(size_t cus):
  shapes_(new Shape *[cus]),
  capacity_(cus),
  current_size_(0)
{
}

brevnov::CompositeShape::CompositeShape(const CompositeShape & cos):
  shapes_(new Shape *[cos.capacity_]),
  capacity_(cos.capacity_),
  current_size_(cos.current_size_)
{
  for (size_t i = 0; i < current_size_; i++)
  {
    try
    {
      shapes_[i] = cos[i]->clone();
    }
    catch (const std::bad_alloc& e)
    {
      clearShape(shapes_, i);
      throw;
    }
  }
}

brevnov::CompositeShape::CompositeShape(CompositeShape && cos) noexcept:
  shapes_(cos.shapes_),
  capacity_(cos.capacity_),
  current_size_(cos.current_size_)
{
  cos.shapes_ = nullptr;
  cos.current_size_ = 0;
  cos.capacity_ = 0;
}

brevnov::CompositeShape & brevnov::CompositeShape::operator=(const brevnov::CompositeShape & cos)
{
  CompositeShape help(cos);
  std::swap(shapes_, help.shapes_);
  std::swap(capacity_, help.capacity_);
  std::swap(current_size_, help.current_size_);
  return *this;
}

brevnov::CompositeShape & brevnov::CompositeShape::operator=(brevnov::CompositeShape && cos) noexcept
{
  clear();
  shapes_ = cos.shapes_;
  capacity_ = cos.capacity_;
  current_size_ = cos.current_size_;
  cos.shapes_ = nullptr;
  cos.current_size_ = 0;
  cos.capacity_ = 0;
  return *this;
}

void brevnov::CompositeShape::add_memory()
{
  constexpr size_t add_number = 10;
  CompositeShape help(capacity_ + add_number);
  for (size_t i = 0; i < current_size_; i++)
  {
    help.shapes_[i] = shapes_[i];
  }
  help.current_size_ = current_size_;
  *this = std::move(help);
}

void brevnov::CompositeShape::push_back(Shape * sp)
{
  if (current_size_ >= capacity_)
  {
    try
    {
      add_memory();
    }
    catch (const std::bad_alloc& e)
    {
      throw std::length_error("Future error!");
    }
  }
  shapes_[current_size_++] = sp;
}

void brevnov::CompositeShape::pop_back()
{
  if (current_size_ == 0)
  {
    throw std::out_of_range("No Shapes for delete");
  }
  delete shapes_[--current_size_];
}

const brevnov::Shape * brevnov::CompositeShape::at(size_t id) const
{
  if (id >= current_size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

brevnov::Shape * brevnov::CompositeShape::at(size_t id)
{
  if (id >= current_size_)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}


const brevnov::Shape * brevnov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

brevnov::Shape * brevnov::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}

bool brevnov::CompositeShape::empty() const noexcept
{
  return current_size_ == 0;
}

size_t brevnov::CompositeShape::size() const noexcept
{
  return current_size_;
}

double brevnov::CompositeShape::getArea() const noexcept
{
  double sum = 0.0;
  for (size_t i = 0; i < current_size_; i++)
  {
    sum += shapes_[i]->getArea();
  }
  return sum;
}

brevnov::rectangle_t brevnov::CompositeShape::getFrameRect() const noexcept
{
  double leftx = shapes_[0]->getFrameRect().pos.x - shapes_[0]->getFrameRect().width;
  double lefty = shapes_[0]->getFrameRect().pos.y - shapes_[0]->getFrameRect().height;
  double rightx = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().width;
  double righty = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().height;
  for (size_t i = 1; i < current_size_; i++)
  {
    double width = shapes_[i]->getFrameRect().width;
    double height = shapes_[i]->getFrameRect().height;
    point_t pos = shapes_[i]->getFrameRect().pos;
    leftx = std::fmin(leftx, pos.x - width);
    lefty = std::fmin(lefty, pos.y - height);
    rightx = std::fmax(rightx, pos.x + width);
    righty = std::fmax(righty, pos.y + height);
  }
  return {rightx - leftx, righty - lefty, {(rightx + leftx) / 2.0, (righty + lefty) / 2.0}};
}

void brevnov::CompositeShape::move(point_t a) noexcept
{
  double dx = a.x - getFrameRect().pos.x;
  double dy = a.y - getFrameRect().pos.y;
  move(dx, dy);
}

void brevnov::CompositeShape::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < current_size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void brevnov::CompositeShape::scale(double k,  point_t scale)
{
  for (size_t i = 0; i < current_size_; ++i)
  {
    point_t start = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(scale);
    point_t end = shapes_[i]->getFrameRect().pos;
    point_t vector = {(end.x - start.x) * k, (end.y - start.y) * k};
    shapes_[i]->check_scale(k);
    shapes_[i]->move(-vector.x,  -vector.y);
  }
}

void brevnov::CompositeShape::scale(double k)
{
  point_t scalep = getFrameRect().pos;
  scale(k, scalep);
}

brevnov::CompositeShape::~CompositeShape()
{
  clear();
}

void brevnov::clearShape(brevnov::Shape ** shapes, size_t i)
{
  for (size_t j = 0; j < i; j++)
  {
    delete shapes[j];
  }
  delete[] shapes;
}
