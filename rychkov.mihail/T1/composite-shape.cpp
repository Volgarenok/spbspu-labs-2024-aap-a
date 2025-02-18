#include "composite-shape.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <memf.hpp>

rychkov::CompositeShape::CompositeShape() noexcept:
  shapes_(nullptr),
  size_(0),
  capacity_(0)
{}
rychkov::CompositeShape::CompositeShape(const CompositeShape& src):
  shapes_(static_cast< Shape** >(malloc(src.size_ * sizeof(Shape*)))),
  size_(src.size_),
  capacity_(src.size_)
{
  if (!shapes_)
  {
    throw std::bad_alloc();
  }
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = src.shapes_[i]->clone();
  }
}
rychkov::CompositeShape::CompositeShape(CompositeShape&& src) noexcept:
  shapes_(std::exchange(src.shapes_, nullptr)),
  size_(std::exchange(src.size_, 0)),
  capacity_(std::exchange(src.capacity_, 0))
{}
rychkov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->~Shape();
    free(shapes_[i]);
  }
  free(shapes_);
}

rychkov::CompositeShape& rychkov::CompositeShape::operator=(const CompositeShape& src)
{
  CompositeShape temp(src);
  std::swap(*this, temp);
  return *this;
}
rychkov::CompositeShape& rychkov::CompositeShape::operator=(CompositeShape&& src) noexcept
{
  CompositeShape(std::move(*this));
  shapes_ = std::exchange(src.shapes_, nullptr);
  size_ = std::exchange(src.size_, 0);
  capacity_ = std::exchange(src.capacity_, 0);
  return *this;
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
    throw std::out_of_range("composite shape index is too big");
  }
  return shapes_[id];
}
const rychkov::Shape* rychkov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("composite shape index is too big");
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
    point_t tempBottomLeft{0, 0}, tempTopRight{0, 0};
    convert(shapes_[i]->getFrameRect(), tempBottomLeft, tempTopRight);
    if ((tempBottomLeft.x == tempTopRight.x) || (tempBottomLeft.y == tempTopRight.y))
    {
      continue;
    }

    if ((bottomLeft.x == topRight.x) || (bottomLeft.y == topRight.y))
    {
      bottomLeft = tempBottomLeft;
      topRight = tempTopRight;
    }
    updateFrame(bottomLeft, topRight, tempBottomLeft, tempTopRight);
  }
  return makeFrame(bottomLeft, topRight);
}
void rychkov::CompositeShape::move(point_t destination) noexcept
{
  point_t center = getFrameRect().pos;
  move(destination.x - center.x, destination.y - center.y);
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
  validateScaleCoefficient(coef);
  unsafeScale(coef);
}
void rychkov::CompositeShape::unsafeScale(double coef) noexcept
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    rychkov::unsafeScale(shapes_[i], coef, center);
  }
}
rychkov::CompositeShape* rychkov::CompositeShape::clone() const
{
  CompositeShape* result = static_cast< CompositeShape* >(malloc(sizeof(CompositeShape)));
  if (!result)
  {
    return nullptr;
  }
  try
  {
    return new (result) CompositeShape(*this);
  }
  catch (...)
  {
    free(result);
    return nullptr;
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
  validateScaleCoefficient(coef);
  unsafeScale(composition, coef, scaleCenter);
}
void rychkov::unsafeScale(CompositeShape& composition, double coef, point_t scaleCenter)
{
  for (size_t i = 0; i < composition.size(); i++)
  {
    unsafeScale(composition[i], coef, scaleCenter);
  }
}
