#include "composite-shape.hpp"
#include <algorithm>
#include <cmath>
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  CompositeShape & CompositeShape::operator=(const CompositeShape & rhs)
  {
    if (&rhs != this)
    {
      Shape ** new_array = creatingNewArray(rhs.array_, rhs.capacity_, rhs.capacity_);
      if (!new_array)
      {
        throw std::bad_alloc();
      }
      clearMemory(array_, shapeCounter_);
      array_ = new_array;
      shapeCounter_ = rhs.shapeCounter_;
      capacity_ = rhs.capacity_;
    }
    return *this;
  }

  CompositeShape::CompositeShape(CompositeShape && rhs)
  {
    array_ = rhs.array_;
    shapeCounter_ = rhs.shapeCounter_;
    capacity_ = rhs.capacity_;
    rhs.array_ = nullptr;
  }

  CompositeShape::~CompositeShape()
  {
    clearMemory(array_, shapeCounter_);
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

  rectangle_t CompositeShape::getFrameRect() const
  {
    double lowerLeftX = 0;
    double lowerLeftY = 0;
    double upperRightX = 0;
    double upperRightY = 0;
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      double height = array_[i]->getFrameRect().height;
      double width = array_[i]->getFrameRect().width;
      point_t scaleCoeff = array_[i]->getFrameRect().pos;
      lowerLeftX = std::fmin(lowerLeftX, scaleCoeff.x - width / 2);
      lowerLeftY = std::fmin(lowerLeftY, scaleCoeff.y - height / 2);
      upperRightX = std::fmax(upperRightX, scaleCoeff.x + width / 2);
      upperRightY = std::fmax(upperRightY, scaleCoeff.y + height / 2);
    }
    return {upperRightX - lowerLeftX, upperRightY - lowerLeftY,
           {(upperRightX + lowerLeftX) / 2, (upperRightY + lowerLeftY) / 2}};
  }

  void CompositeShape::move(point_t Z)
  {
    double dx = Z.x - getFrameRect().pos.x;
    double dy = Z.y - getFrameRect().pos.y;
    for (size_t i = 0; i < shapeCounter_; i++)
    {
      array_[i]->move(dx, dy);
    }
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
      point_t vector = {(afterScale.x - beforeScale.x) * scaleCoeff, (afterScale.y - beforeScale.y) * scaleCoeff};
      array_[i]->scale(scaleCoeff);
      array_[i]->move(-vector.x, -vector.y);
    }
  }

  void CompositeShape::push_back(Shape* shp)
  {
    if (shapeCounter_ + 1 == capacity_)
    {
      Shape ** new_array = creatingNewArray(array_, capacity_, 2 * capacity_);
      if (!new_array)
      {
        throw std::bad_alloc();
      }
      clearMemory(array_, shapeCounter_);
      array_ = new_array;
      capacity_ = 2 * capacity_;
    }
    array_[shapeCounter_++] = shp;
  }

  void CompositeShape::pop_back() noexcept
  {
    delete array_[shapeCounter_--];
  }

  Shape* CompositeShape::at(size_t id) const
  {
    if (id >= shapeCounter_)
    {
      throw std::out_of_range("Out of range\n");
    }
    return array_[id];
  }

  Shape* CompositeShape::operator[](size_t id) const noexcept
  {
    return array_[id];
  }

  bool CompositeShape::empty() const
  {
    return (shapeCounter_ == 0);
  }

  size_t CompositeShape::size() const
  {
    return shapeCounter_;
  }

  Shape** CompositeShape::creatingNewArray(Shape** array, size_t old_size, size_t new_size)
  {
    Shape** created = nullptr;
    try
    {
      created = new Shape*[new_size];
      for (size_t i = 0; i < old_size; ++i)
        {
          created[i] = array[i];
        }
    }
    catch (const std::exception& e)
    {
      delete[] created;
      return nullptr;
    }
    return created;
  }
}
