#include "composite-shape.hpp"
#include <cmath>
#include <stdexcept>
#include "figureactions.hpp"

namespace
{
  void fillArrayWithClones(tkach::Shape** now, const tkach::Shape* const* const other, const size_t size, size_t& true_size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      now[i] = other[i]->clone();
      true_size++;
    }
  }

  void fillFromOneArrayToAnother(tkach::Shape** now, tkach::Shape* const* const other, const size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      now[i] = other[i];
    }
  }
}

tkach::CompositeShape::CompositeShape():
  size_(0),
  shapes_(nullptr)
{}

tkach::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  size_(other.size_),
  shapes_(other.shapes_)
{
  other.size_ = 0;
  other.shapes_ = nullptr;
}

tkach::CompositeShape::CompositeShape(const CompositeShape& other):
  size_(other.size_),
  shapes_(new Shape*[size_])
{
  size_t true_size = 0;
  try
  {
    fillArrayWithClones(shapes_, other.shapes_, size_, true_size);
  }
  catch (const std::bad_alloc&)
  {
    for (size_t i = 0; i < true_size; ++i)
    {
      delete shapes_[i];
    }
    delete[] shapes_;
    size_ = 0;
    shapes_ = nullptr;
    throw;
  }
}

tkach::CompositeShape& tkach::CompositeShape::operator=(const CompositeShape& other)
{
  if (this != &other)
  {
    Shape** new_shapes = new Shape*[other.size_];
    size_t true_size = 0;
    try
    {
      fillArrayWithClones(new_shapes, other.shapes_, other.size_, true_size);
    }
    catch (const std::bad_alloc&)
    {
      for (size_t i = 0; i < true_size; ++i)
      {
        delete new_shapes[i];
      }
      delete[] new_shapes;
      throw;
    }
    delete[] shapes_;
    shapes_ = new_shapes;
    size_ = other.size_;
  }
  return *this;
}

tkach::CompositeShape& tkach::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this != &other)
  {
    delete[] shapes_;
    size_ = other.size_;
    shapes_ = other.shapes_;
    other.shapes_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

double tkach::CompositeShape::getArea() const
{
  return getTotalArea(shapes_, size_);
}

tkach::rectangle_t tkach::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    return {0.0, 0.0, {0.0, 0.0}};
  }
  double left = 0.0, right = 0.0, top = 0.0, bot = 0.0;
  rectangle_t shape_rect = shapes_[0]->getFrameRect();
  left = shape_rect.pos.x - shape_rect.width / 2.0;
  bot = shape_rect.pos.y - shape_rect.height / 2.0;
  for (size_t i = 1; i < size_; ++i)
  {
    shape_rect = shapes_[i]->getFrameRect();
    left = std::min(left, shape_rect.pos.x - shape_rect.width / 2.0);
    bot = std::min(bot, shape_rect.pos.y - shape_rect.height / 2.0);
    right = std::max(right, shape_rect.pos.x + shape_rect.width / 2.0);
    top = std::max(top, shape_rect.pos.y + shape_rect.height / 2.0);
  }
  return {right - left, top - bot, {(left + right) / 2.0, (top + bot) / 2.0}};
}

tkach::CompositeShape::~CompositeShape()
{
  delete[] shapes_;
}

void tkach::CompositeShape::move(const double add_to_x, const double add_to_y)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i]->move(add_to_x, add_to_y);
  }
}

void tkach::CompositeShape::move(const point_t& point_to_move)
{
  point_t frame_center = getFrameRect().pos;
  move(frame_center.x - point_to_move.x, frame_center.y - point_to_move.y);
}

void tkach::CompositeShape::push_back(Shape* const shp)
{
  if (shp == nullptr)
  {
    throw std::invalid_argument("No shape");
  }
  Shape** new_shapes = new Shape*[size_ + 1];
  fillFromOneArrayToAnother(new_shapes, shapes_, size_);
  new_shapes[size_++] = shp;
  delete[] shapes_;
  shapes_ = new_shapes;
}

void tkach::CompositeShape::pop_back()
{
  if (size_ == 0)
  {
    throw std::logic_error("Empty compositeshape");
  }
  Shape** new_shapes = new Shape*[--size_];
  fillFromOneArrayToAnother(new_shapes, shapes_, size_);
  delete[] shapes_;
  shapes_ = new_shapes;
}

tkach::Shape* tkach::CompositeShape::at(const size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return shapes_[id];
}

const tkach::Shape* tkach::CompositeShape::at(const size_t id) const
{
  return const_cast< CompositeShape* >(this)->at(id);
}

tkach::Shape* tkach::CompositeShape::operator[](const size_t id)
{
  return shapes_[id];
}

const tkach::Shape* tkach::CompositeShape::operator[](const size_t id) const
{
  return shapes_[id];
}

bool tkach::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}

size_t tkach::CompositeShape::size() const noexcept
{
  return size_;
}

void tkach::CompositeShape::doUnsafeScale(const double multiplier)
{
  doUnsaveIsoScaleShapes(shapes_, size_, multiplier, getFrameRect().pos);
}

void tkach::CompositeShape::scale(const double multiplier)
{
  doSaveIsoScaleShapes(shapes_, size_, multiplier, getFrameRect().pos);
}
