#include "composite-shape.hpp"
#include <algorithm>
#include <cmath>
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  CompositeShape::CompositeShape(size_t capacity):
    array_(new Shape*[capacity]),
    capacity_(capacity),
    shapeCounter_(0)
  {}

  CompositeShape::CompositeShape(const CompositeShape& rhs):
    array_(new Shape*[rhs.capacity_]),
    capacity_(rhs.capacity_),
    shapeCounter_(rhs.shapeCounter_)
  {
    try
    {
      cloneArray(array_, rhs.array_, shapeCounter_);
    }
    catch (const std::bad_alloc&)
    {
      clear();
    }
  }

  CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept:
    array_(rhs.array_),
    capacity_(rhs.capacity_),
    shapeCounter_(rhs.shapeCounter_)
  {
    rhs.array_ = nullptr;
    rhs.shapeCounter_ = 0;
    rhs.capacity_ = 0;
  }

  CompositeShape::~CompositeShape()
  {
    clear();
  }

  CompositeShape& CompositeShape::operator=(const CompositeShape& rhs)
  {
    if (&rhs != this)
    {
      CompositeShape cs(rhs);
      swap(cs);
    }
    return *this;
  }

  CompositeShape& CompositeShape::operator=(CompositeShape&& rhs) noexcept
  {
    if (std::addressof(rhs) != this)
    {
      clear();
      swap(rhs);
    }
    return *this;
  }

  const Shape* CompositeShape::operator[](size_t id) const noexcept
  {
    return array_[id];
  }

  Shape* CompositeShape::operator[](size_t id) noexcept
  {
    return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).operator[](id));
  }

  double CompositeShape::getArea() const
  {
    double area = 0.0;
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      area += array_[i]->getArea();
    }
    return area;
  }

  CompositeShape* CompositeShape::clone() const
  {
    return new CompositeShape(*this);
  }

  rectangle_t CompositeShape::getFrameRect() const
  {
    double lLX = 0;
    double lLY = 0;
    double uRX = 0;
    double uRY = 0;
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      double height = array_[i]->getFrameRect().height;
      double width = array_[i]->getFrameRect().width;
      point_t scaleCoeff = array_[i]->getFrameRect().pos;
      lLX = std::fmin(lLX, scaleCoeff.x - width / 2);
      lLY = std::fmin(lLY, scaleCoeff.y - height / 2);
      uRX = std::fmax(uRX, scaleCoeff.x + width / 2);
      uRY = std::fmax(uRY, scaleCoeff.y + height / 2);
    }
    return { uRX - lLX, uRY - lLY, { (uRX + lLX) / 2, (uRY + lLY) / 2} };
  }

  void CompositeShape::move(point_t scalePoint)
  {
    double dx = scalePoint.x - getFrameRect().pos.x;
    double dy = scalePoint.y - getFrameRect().pos.y;
    move(dx, dy);
  }

  void CompositeShape::move(double dx, double dy)
  {
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      array_[i]->move(dx, dy);
    }
  }

  void CompositeShape::scale(double scaleCoeff)
  {
    point_t scalePoint = getFrameRect().pos;
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      point_t beforeScale = array_[i]->getFrameRect().pos;
      array_[i]->move(scalePoint);
      point_t afterScale = array_[i]->getFrameRect().pos;
      point_t vector = { (afterScale.x - beforeScale.x) * scaleCoeff, (afterScale.y - beforeScale.y) * scaleCoeff };
      array_[i]->scale(scaleCoeff);
      array_[i]->move(-vector.x, -vector.y);
    }
  }

  void CompositeShape::push_back(Shape* shp)
  {
    if (shapeCounter_ >= capacity_)
    {
      const size_t newCapacity = capacity_ * 2 + 1;
      scaleArray(newCapacity);
    }
    array_[shapeCounter_++] = shp;
  }

  void CompositeShape::pop_back()
  {
    if (shapeCounter_ == 0)
    {
      throw std::out_of_range("No compShape");
    }
    delete array_[shapeCounter_ - 1];
    shapeCounter_--;
  }

  const Shape* CompositeShape::at(size_t id) const
  {
    if (id >= shapeCounter_)
    {
      throw std::out_of_range("Index bigger than realSize");
    }
    return array_[id];
  }

  Shape* CompositeShape::at(size_t id)
  {
    return const_cast< Shape* >(static_cast< const CompositeShape& >(*this).at(id));
  }

  bool CompositeShape::empty() const noexcept
  {
    return (shapeCounter_ == 0);
  }

  size_t CompositeShape::size() const noexcept
  {
    return shapeCounter_;
  }

  void CompositeShape::scaleEverything(CompositeShape *compShape, point_t scalePoint, double scaleCoeff)
  {
    size_t size = compShape->size();
    for (size_t i = 0; i < size; i++)
    {
      point_t start = compShape[i].getFrameRect().pos;
      compShape[i].move(scalePoint);
      point_t end = compShape[i].getFrameRect().pos;
      point_t vector = { (end.x - start.x) * scaleCoeff, (end.y - start.y) * scaleCoeff };
      compShape[i].scale(scaleCoeff);
      compShape[i].move(-vector.x,  -vector.y);
    }
  }

  void CompositeShape::swap(CompositeShape& rhs)
  {
    std::swap(array_, rhs.array_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(shapeCounter_, rhs.shapeCounter_);
  }

  void CompositeShape::scaleArray(size_t size)
  {
    CompositeShape newArray(size);
    cloneArray(newArray.array_, array_, shapeCounter_);
    newArray.shapeCounter_ += shapeCounter_;
    swap(newArray);
  }

  void CompositeShape::clear()
  {
    for (size_t i = 0; i < shapeCounter_; ++i)
    {
      delete array_[i];
    }
    delete[] array_;
  }

  void cloneArray(Shape** destination, Shape** source, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      destination[i] = source[i]->clone();
    }
  }
}

