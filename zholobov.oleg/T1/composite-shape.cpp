#include "composite-shape.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "shapes_utils.hpp"
#include "square.hpp"

zholobov::CompositeShape::CompositeShape() noexcept:
  items_(),
  items_num_(0)
{}

zholobov::CompositeShape::CompositeShape(const CompositeShape& other):
  items_(),
  items_num_(0)
{
  try {
    for (items_num_ = 0; items_num_ < other.items_num_; ++items_num_) {
      items_[items_num_] = other.items_[items_num_]->clone();
    }
  } catch (const std::exception&) {
    for (size_t i = 0; i < items_num_; ++i) {
      delete items_[i];
    }
    throw;
  }
}

zholobov::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  CompositeShape()
{
  swap(other);
}

zholobov::CompositeShape::~CompositeShape()
{
  clear();
}

zholobov::CompositeShape& zholobov::CompositeShape::operator=(const CompositeShape& other)
{
  if (this != std::addressof(other)) {
    CompositeShape temp(other);
    swap(temp);
  }
  return *this;
}

zholobov::CompositeShape& zholobov::CompositeShape::operator=(zholobov::CompositeShape&& other) noexcept
{
  if (this != std::addressof(other)) {
    clear();
    swap(other);
  }
  return *this;
}

void zholobov::CompositeShape::push_back(Shape* shape)
{
  if (items_num_ == max_elem_num) {
    throw std::out_of_range("CompositeShape storage is full");
  }
  items_[items_num_++] = shape;
}

void zholobov::CompositeShape::pop_back()
{
  if (items_num_ == 0) {
    throw std::out_of_range("CompositeShape storage is empty");
  }
  delete items_[--items_num_];
}

zholobov::Shape* zholobov::CompositeShape::at(size_t idx)
{
  if (idx > items_num_) {
    throw std::out_of_range("idx out of range");
  }
  return items_[idx];
}

const zholobov::Shape* zholobov::CompositeShape::at(size_t idx) const
{
  if (idx > items_num_) {
    throw std::out_of_range("idx out of range");
  }
  return items_[idx];
}

zholobov::Shape* zholobov::CompositeShape::operator[](size_t idx) noexcept
{
  return items_[idx];
}

const zholobov::Shape* zholobov::CompositeShape::operator[](size_t idx) const noexcept
{
  return items_[idx];
}

bool zholobov::CompositeShape::empty() const noexcept
{
  return items_num_ == 0;
}

size_t zholobov::CompositeShape::size() const noexcept
{
  return items_num_;
}

void zholobov::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < items_num_; ++i) {
    delete items_[i];
  }
  items_num_ = 0;
}

double zholobov::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < items_num_; ++i) {
    sum += items_[i]->getArea();
  }
  return sum;
}

zholobov::rectangle_t zholobov::CompositeShape::getFrameRect() const
{
  double left = std::numeric_limits< double >::max();
  double right = std::numeric_limits< double >::lowest();
  double down = std::numeric_limits< double >::max();
  double up = std::numeric_limits< double >::lowest();

  for (size_t i = 0; i < items_num_; ++i) {
    rectangle_t cur_rect = items_[i]->getFrameRect();
    double cur_left = cur_rect.pos.x - cur_rect.width / 2.0;
    double cur_right = cur_rect.pos.x + cur_rect.width / 2.0;
    double cur_down = cur_rect.pos.y - cur_rect.height / 2.0;
    double cur_up = cur_rect.pos.y + cur_rect.height / 2.0;
    left = std::min(cur_left, left);
    right = std::max(cur_right, right);
    down = std::min(cur_down, down);
    up = std::max(cur_up, up);
  }
  return rectangle_t{right - left, up - down, {(right + left) / 2.0, (up + down) / 2.0}};
}

void zholobov::CompositeShape::move(point_t p)
{
  rectangle_t rect = getFrameRect();
  move(p.x - rect.pos.x, p.y - rect.pos.y);
}

void zholobov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < items_num_; ++i) {
    items_[i]->move(dx, dy);
  }
}

void zholobov::CompositeShape::scale(double k)
{
  scale_relative(getFrameRect().pos, k);
}

void zholobov::CompositeShape::print(std::ostream& output) const
{
  output << std::fixed << std::setprecision(1) << getArea();
  for (size_t i = 0; i < items_num_; ++i) {
    rectangle_t rect = items_[i]->getFrameRect();
    output << " " << rect.pos.x - rect.width / 2.0 << " " << rect.pos.y - rect.height / 2.0;
    output << " " << rect.pos.x + rect.width / 2.0 << " " << rect.pos.y + rect.height / 2.0;
  }
}

void zholobov::CompositeShape::scale_relative(point_t pos, double scale_factor)
{
  if (scale_factor <= 0.0) {
    throw std::out_of_range("Invalid scale factor");
  }
  for (size_t i = 0; i < items_num_; ++i) {
    items_[i]->scale_no_check(scale_factor);
    zholobov::rectangle_t rect = items_[i]->getFrameRect();
    zholobov::point_t new_pos;
    new_pos.x = (rect.pos.x - pos.x) * scale_factor + pos.x;
    new_pos.y = (rect.pos.y - pos.y) * scale_factor + pos.y;
    items_[i]->move(new_pos);
  }
}

void zholobov::CompositeShape::swap(CompositeShape& other) noexcept
{
  Shape** smaller_array = nullptr;
  Shape** bigger_array = nullptr;
  size_t swap_upto_index = 0;
  size_t move_upto_index = 0;
  if (items_num_ < other.items_num_) {
    smaller_array = items_;
    bigger_array = other.items_;
    swap_upto_index = items_num_;
    move_upto_index = other.items_num_;
  } else {
    smaller_array = other.items_;
    bigger_array = items_;
    swap_upto_index = other.items_num_;
    move_upto_index = items_num_;
  }
  for (size_t i = 0; i < swap_upto_index; ++i) {
    std::swap(smaller_array[i], bigger_array[i]);
  }
  for (size_t i = swap_upto_index; i < move_upto_index; ++i) {
    smaller_array[i] = bigger_array[i];
  }
  std::swap(items_num_, other.items_num_);
}
