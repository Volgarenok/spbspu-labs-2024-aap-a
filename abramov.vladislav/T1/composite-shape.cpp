#include "composite-shapes.hpp"
#icnlude <stdexcept>

namespace abramov
{
  double CompositeShapes::getArea(size_t id) const
  {
    return shapeptrs_[id]->getArea();
  }

  rectangle_t CompositeShapes::getFrameRect(size_t id) const
  {
    return shapeptrs_[id]->getArea();
  }

  void CompositeShapes::move(size_t id, point_t p)
  {
    return shapeptrs_[id]->move(point_t p);
  }

  void CompositeShapes::move(size_t id, double dx, double dy)
  {
    return shapeptrs_[id]->move(double dx, double dy);
  }

  void CompositeShapes::scale(size_t id, double k)
  {
    return shapeptrs_[id]->scale(double k);
  }

  void CompositeShapes::push_back(Shape *shp)
  {
    if (capacity_ == shapes_)
    {
      shapeptrs_ = expandArray(shapeptrs_, capacity_);
      if (shapeptrs_ == nullptr)
      {
        throw std::bad_alloc();
      }
    }
    shapeptrs[++shapes_] = shp;
  }

  void CompositeShapes::pop_back()
  {
    delete shapeptrs_[shapes_ - 1];
    shapeptrs_[shapes_ - 1] = nullptr;
  }

  Shape *CompositeShapes::at(size_t id) const
  {
    if (id >= shapes_)
    {
      throw std::out_of_range();
    }
    return shapeptrs_[id];
  }

  Shape *CompositeShapes::operator[](size_t id) const noexcept
  {
    return shapeptrs_[id];
  }

  bool CompositeShapes::empty() const
  {
    if (shapes_ == 0)
    {
      return true;
    }
    return false;
  }

  size_t CompositeShapes::size() const
  {
    return shapes_;
  }

  Shape *CompositeShapes::clone()
  {
    return nullptr;
  }

  Shape *expandArray(Shape * arr, size_t capacity)
  {
    Shape *array = nullptr;
    try
    {
      array = new Shape[capacity * 2];
    }
    catch (const std::bad_alloc &e)
    {
      return nullptr;
    }
    for (size_t i = 0; i < capacity; ++i)
    {
      array[i] = arr[i];
    }
    return array;
  }
}
