#include "composite-shape.hpp"
#include <stdexcept>
#include "figureactions.hpp"

namespace
{
  double getTotalArea(const tkach::Shape* const* const shape_array, const size_t counter_of_shapes)
  {
    double sum = 0.0;
    for (size_t i = 0; i < counter_of_shapes; ++i)
    {
      sum += shape_array[i]->getArea();
    }
    return sum;
  }

  void fillCloneArray(tkach::Shape** now, const tkach::Shape* const* const other, const size_t size, size_t& true_size)
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

  void deleteShapesFromArray(tkach::Shape** shapes_array, const size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      delete shapes_array[i];
    }
  }

  tkach::Shape** getCompoiteShapeFromOther(const tkach::Shape* const* const other_array, const size_t size)
  {
    tkach::Shape** shapes = new tkach::Shape*[size];
    size_t true_size = 0;
    try
    {
      fillCloneArray(shapes, other_array, size, true_size);
    }
    catch (const std::bad_alloc&)
    {
      deleteShapesFromArray(shapes, true_size);
      throw;
    }
    return shapes;
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
  shapes_(getCompoiteShapeFromOther(other.shapes_, size_))
{}

tkach::CompositeShape& tkach::CompositeShape::operator=(const CompositeShape& other)
{
  if (this == std::addressof(other))
  {
    return *this;
  }
  CompositeShape temp(other);
  swap(temp);
  return *this;
}

tkach::CompositeShape& tkach::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this == std::addressof(other))
  {
    return *this;
  }
  CompositeShape temp(std::move(other));
  swap(temp);
  return *this;
}

double tkach::CompositeShape::getArea() const
{
  return getTotalArea(shapes_, size_);
}

tkach::rectangle_t tkach::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("No shapes for FrameRect");
  }
  rectangle_t shape_rect = shapes_[0]->getFrameRect();
  double left = shape_rect.pos.x - shape_rect.width / 2.0;
  double bot = shape_rect.pos.y - shape_rect.height / 2.0;
  double right = shape_rect.pos.x + shape_rect.width / 2.0;
  double top = shape_rect.pos.y + shape_rect.height / 2.0;
  for (size_t i = 1; i < size(); ++i)
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
  for (size_t i = 0; i < size(); ++i)
  {
    shapes_[i]->move(add_to_x, add_to_y);
  }
}

void tkach::CompositeShape::move(const point_t& point_to_move)
{
  point_t frame_center = getFrameRect().pos;
  move(frame_center.x - point_to_move.x, frame_center.y - point_to_move.y);
}

void tkach::CompositeShape::pushBack(Shape* const shp)
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

void tkach::CompositeShape::popBack()
{
  if (empty())
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
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->at(id));
}

const tkach::Shape* tkach::CompositeShape::at(const size_t id) const
{
  if (id >= size())
  {
    throw std::out_of_range("Index is out of range");
  }
  return shapes_[id];
}

tkach::Shape* tkach::CompositeShape::operator[](const size_t id)
{
  return const_cast< Shape* >(static_cast< const CompositeShape* >(this)->operator[](id));
}

const tkach::Shape* tkach::CompositeShape::operator[](const size_t id) const
{
  return shapes_[id];
}

bool tkach::CompositeShape::empty() const noexcept
{
  return size() == 0;
}

size_t tkach::CompositeShape::size() const noexcept
{
  return size_;
}

void tkach::CompositeShape::swap(CompositeShape& other) noexcept
{
  std::swap(size_, other.size_);
  std::swap(shapes_, other.shapes_);
}

void tkach::CompositeShape::doUnsafeScale(const double multiplier)
{
  doUnsafeIsoScaleCompShape(*this, multiplier, getFrameRect().pos);
}

void tkach::CompositeShape::scale(const double multiplier)
{
  if (multiplier <= 0)
  {
    throw std::logic_error("Not positive coef");
  }
  doUnsafeScale(multiplier);
}
