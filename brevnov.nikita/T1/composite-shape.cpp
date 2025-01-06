#include "composite-shape.hpp"
#include <utility>
#include <stdexcept>
#include <cmath>

void brevnov::CompositeShape::print_frame_coordinates(std::ostream & out)
{
  for (size_t i = 0; i < current_size_, i++)
  {
    rectangle_t frame = shapes_[i]->getFrameRect();
    double leftx = frame.pos_.x_ - frame.width_ / 2.0;
    double lefty = frame.pos_.y_ - frame.height_ / 2.0;
    double rightx = frame.pos_.x_ + frame.width_ / 2.0;
    double righty = frame.pos_.y_ + frame.height_ / 2.0;
    out << leftx << " " << lefty << " " <<  rightx << " " << righty;
  }
}

void brevnov::CompositeShape::clear()
{
  for (size_t i = 0; i < current_size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

brevnov::CompositeShape::CompositeShape(size_t cus):
  shapes_(nullptr),
  capacity_(cus),
  current_size_(0)
{
  shapes_ = new Shape *[capacity_];
}

brevnov::CompositeShape::CompositeShape(CompositeShape & cos):
  shapes_(nullptr),
  capacity_(cos.capacity_),
  current_size_(cos.current_size_)
{
  shapes_ = new Shape *[capacity_];
  for (size_t i = 0; i < capacity_; i++)
  {
    shapes_[i] = cos[i];
  }
}

brevnov::CompositeShape::CompositeShape(CompositeShape && cos) noexcept:
  shapes_(cos.shapes_),
  capacity_(cos.capacity_),
  current_size_(cos.current_size_)
{
  cos.shape = nullptr;
  cmp.current_size_ = 0;
  cmp.capacity_ = 0;
}

brevnov::CompositeShape & operator=(CompositeShape & cmp)
{
  CompositeShape result(cmp);
  clear();
  return result;
}

brevnov::CompositeShape & operator=(CompositeShape && cmp) noexcept
{
  clear();
  CompositeShape result(std::move(cmp));
  return result;
}

void brevnov::CompositeShape::add_memory()
{
  constexpr size_t add_number = 10;
  CompositeShape help(capacity_ + add_number);
  for (size_t i = 0; i < current_size_; i++)
  {
    help[i] = shapes_[i];
    help.current_size_++;
  }
  *this = std::moved(help);
}

void brevnov::CompositeShape::push_back(Shape * sp)
{
  if (current_size_ >= capacity_)
  {
    add_memory();
  }
  shape[current_size_++] = sp;
}

void brevnov::CompositeShape::pop_back()
{
  if (current_size_ == 0)
  {
    throw std::out_of_range("No Shapes for delete");
  }
  delete shapes_[--current_size_];
}

brevnov::Shape * brevnov::CompositeShape::at(size_t id)
{
  if (id >= current_size_ || id < 0)
  {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[id];
}

brevnov::Shape * brevnov::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}

bool brevnov::CompositeShape::empty() noexcept
{
  return current_size_ == 0;
}

size_t brevnov::CompositeShape::size() noexcept
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
  double leftx = 0.0, lefty = 0.0, rightx = 0.0, righty = 0.0;
  for (size_t i = 0; i < current_size_; i++)
  {
    double width = shapes_[i]->getFrameRect().width_;
    double height = shapes_[i]->getFrameRect().height_;
    point_t pos = shapes_[i]->getFrameRect().pos_;
    leftx = std::fmin(leftx, pos.x_ - width);
    lefty = std::fmin(lefty, pos.y_ - height);
    rightx = std::fmax(rightx, pos.x_ + width);
    righty = std::fmax(righty, pos.y_ + height);
  }
  return {rightx - leftx, righty - lefty, {(rightx + leftx) / 2.0, (righty + lefty) / 2.0}};
}

void brevnov::CompositeShape::move(point_t a) noexcept
{
  double dx = a.x_ - getFrameRect().pos_.x_;
  double dy = a.y_ - getFrameRect().pos_.y_;
  move(dx, dy);
}

void brevnov::CompositeShape::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i < current_size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void brevnov::CompositeShape::scale(double k,  point_t scale) noexcept
{
  for (size_t i = 0; i < current_size_; ++i)
  {
    point_t start = shapes_[i]->getFrameRect().pos_;
    shapes_[i]->move(scale);
    point_t end = shapes_[i]->getFrameRect().pos_;
    point_t vector = {(end.x_ - start.x_) * k, (end.y_ - start.y_) * k};
    shapes_[i]->scale(k);
    shapes_[i]->move(-vector.x_,  -vector.y_);
  }
}

void brevnov::CompositeShape::scale(double k) noexcept
{
  point_t scalep = getFrameRect().pos_;
  scale(k, scalep);
}

brevnov::CompositeShape::~CompositeShape()
{
  clear();
}
