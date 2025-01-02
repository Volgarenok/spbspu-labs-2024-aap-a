#include "composite-shape.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <memf.hpp>

rychkov::CompositeShape::CompositeShape():
  shapes_(nullptr),
  size_(0),
  capacity_(0)
{}
rychkov::CompositeShape::CompositeShape(CompositeShape&& src) noexcept:
  shapes_(std::exchange(src.shapes_, nullptr)),
  size_(std::exchange(src.size_, 0)),
  capacity_(std::exchange(src.capacity_, 0))
{}
rychkov::CompositeShape& rychkov::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  CompositeShape(std::move(*this));
  shapes_ = std::exchange(src.shapes_, nullptr);
  size_ = std::exchange(src.size_, 0);
  capacity_ = std::exchange(src.capacity_, 0);
  return *this;
}
rychkov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->~Shape();
    free(shapes_[i]);
  }
  free(shapes_);
}

rychkov::Shape* rychkov::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}
const rychkov::Shape* rychkov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}
rychkov::Shape* rychkov::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::length_error("composite shape index is too big");
  }
  return shapes_[id];
}
const rychkov::Shape* rychkov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::length_error("composite shape index is too big");
  }
  return shapes_[id];
}

double rychkov::CompositeShape::getArea() const noexcept
{
  double result = 0;
  for (size_t i = 0; i < size_; i++)
  {
    result += shapes_[i]->getArea();
  }
  return result;
}
rychkov::rectangle_t rychkov::CompositeShape::getFrameRect() const noexcept
{
  point_t bottomLeft{0, 0}, topRight{0, 0};
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t tempFrame = shapes_[0]->getFrameRect();
    if ((tempFrame.height == 0) || (tempFrame.width == 0))
    {
      continue;
    }

    point_t tempBottomLeft = {tempFrame.pos.x - tempFrame.width / 2, tempFrame.pos.y - tempFrame.height / 2};
    point_t tempTopRight = {tempFrame.pos.x + tempFrame.width / 2, tempFrame.pos.y + tempFrame.height / 2};
    if ((bottomLeft.x == topRight.x) || (bottomLeft.y == topRight.y))
    {
      bottomLeft = tempBottomLeft;
      topRight = tempTopRight;
    }
    bottomLeft.x = std::min(bottomLeft.x, tempBottomLeft.x);
    bottomLeft.y = std::min(bottomLeft.y, tempBottomLeft.y);
    topRight.x = std::max(topRight.x, tempTopRight.x);
    topRight.y = std::max(topRight.y, tempTopRight.y);
  }
  return makeFrame(bottomLeft, topRight);
}
void rychkov::CompositeShape::move(point_t destination) noexcept
{
  rectangle_t tempFrame = getFrameRect();
  move(destination.x - tempFrame.pos.x, destination.y - tempFrame.pos.y);
}
void rychkov::CompositeShape::move(double deltaX, double deltaY) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(deltaX, deltaY);
  }
}
void rychkov::CompositeShape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("scale can't be executed with non-positive coefficient");
  }
  rectangle_t compositionFrame = getFrameRect();
  for (size_t i = 0; i < size_; i++)
  {
    rychkov::scale(shapes_[i], coef, compositionFrame.pos);
  }
}

bool rychkov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t rychkov::CompositeShape::size() const noexcept
{
  return size_;
}
void rychkov::CompositeShape::push_back(Shape* value)
{
  if (size_ >= capacity_)
  {
    size_t newCapacity = size_ * 2 + 1;
    Shape** temp = reallocate(shapes_, capacity_, newCapacity);
    if (!temp)
    {
      throw std::bad_alloc();
    }
    shapes_ = temp;
    capacity_ = newCapacity;
  }
  shapes_[size_++] = value;
}
void rychkov::CompositeShape::pop_back()
{
  size_--;
  shapes_[size_]->~Shape();
  free(shapes_[size_]);
}
rychkov::Shape** rychkov::CompositeShape::reallocate(Shape** shapes, size_t oldSize, size_t newSize)
{
  char* temp = realloc(reinterpret_cast< char* >(shapes), oldSize * sizeof(Shape*),
        newSize * sizeof(Shape*));
  return reinterpret_cast< Shape** >(temp);
}

void rychkov::scale(CompositeShape& composition, double coef, point_t scaleCenter)
{
  for (size_t i = 0; i < composition.size(); i++)
  {
    scale(composition[i], coef, scaleCenter);
  }
}
