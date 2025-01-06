#include "composite-shape.hpp"
#include <utility>
#include <stdexcept>
#include <cmath>

void brevnov::CompositeShape::print_frame_coordinates(std::ostream & out)
{
  for (size_t i = 0; i < current_size_; i++)
  {
    if (i > 0)
    {
      out << " ";
    }
    rectangle_t frame = shapes_[i]->getFrameRect();
    double leftx = frame.pos.x - frame.width / 2.0;
    double lefty = frame.pos.y - frame.height / 2.0;
    double rightx = frame.pos.x + frame.width / 2.0;
    double righty = frame.pos.y + frame.height / 2.0;
    out << leftx << " " << lefty << " " <<  rightx << " " << righty;
  }
}

void brevnov::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < current_size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

brevnov::CompositeShape::CompositeShape(size_t cus):
  shapes_(nullptr),
  capacity(cus),
  current_size_(0)
{
  shapes_ = new Shape *[capacity];
}

brevnov::CompositeShape::CompositeShape(CompositeShape & cos):
  shapes_(nullptr),
  capacity(cos.capacity),
  current_size_(cos.current_size_)
{
  shapes_ = new Shape *[capacity];
  for (size_t i = 0; i < current_size_; i++)
  {
    shapes_[i] = cos[i];
  }
}

brevnov::CompositeShape::CompositeShape(CompositeShape && cos) noexcept:
  shapes_(cos.shapes_),
  capacity(cos.capacity),
  current_size_(cos.current_size_)
{
  cos.shapes_ = nullptr;
  cos.current_size_ = 0;
  cos.capacity = 0;
}

brevnov::CompositeShape & brevnov::CompositeShape::operator=(brevnov::CompositeShape & cos)
{
  Shape ** help = new Shape *[cos.capacity];
  clear();
  shapes_ = help;
  capacity = cos.capacity;
  current_size_ = cos.current_size_;
  for (size_t i = 0; i < current_size_; i++)
  {
    shapes_[i] = cos[i];
  }
  return *this;
}

brevnov::CompositeShape & brevnov::CompositeShape::operator=(brevnov::CompositeShape && cos) noexcept
{
  clear();
  shapes_ = cos.shapes_;
  capacity = cos.capacity;
  current_size_ = cos.current_size_;
  cos.shapes_ = nullptr;
  cos.current_size_ = 0;
  cos.capacity = 0;
  return *this;
}

void brevnov::CompositeShape::add_memory()
{
  constexpr size_t add_number = 10;
  CompositeShape help(capacity + add_number);
  for (size_t i = 0; i < current_size_; i++)
  {
    help.shapes_[i] = shapes_[i];
  }
  help.current_size_ = current_size_;
  *this = std::move(help);
}

void brevnov::CompositeShape::push_back(Shape * sp)
{
  if (current_size_ >= capacity)
  {
    add_memory();
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

brevnov::Shape * brevnov::CompositeShape::at(size_t id)
{
  if (id >= current_size_)
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

void brevnov::CompositeShape::scale(double k,  point_t scale) noexcept
{
  for (size_t i = 0; i < current_size_; ++i)
  {
    point_t start = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(scale);
    point_t end = shapes_[i]->getFrameRect().pos;
    point_t vector = {(end.x - start.x) * k, (end.y - start.y) * k};
    shapes_[i]->scale(k);
    shapes_[i]->move(-vector.x,  -vector.y);
  }
}

void brevnov::CompositeShape::scale(double k) noexcept
{
  point_t scalep = getFrameRect().pos;
  scale(k, scalep);
}

brevnov::CompositeShape::~CompositeShape()
{
  clear();
}
