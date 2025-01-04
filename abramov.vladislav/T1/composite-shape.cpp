#include "composite-shape.hpp"
#include <stdexcept>

namespace abramov
{
  CompositeShape::CompositeShape(size_t capacity):
   shapes_(0),
   capacity_(capacity),
   shapeptrs_(nullptr)
  {
    shapeptrs_ = new Shape*[capacity];
    for (size_t i = 0; i < capacity; ++i)
    {
      shapeptrs_[i] = nullptr;
    }
  }

  CompositeShape::CompositeShape(const CompositeShape &comp_shp)
  {
    shapes_ = comp_shp.shapes_;
    capacity_ = comp_shp.capacity_;
    shapeptrs_ = nullptr;
    shapeptrs_ = new Shape*[capacity_];
    for (size_t i = 0; i < shapes_; ++i)
    {
      shapeptrs_[i] = comp_shp.shapeptrs_[i];
    }
  }

  CompositeShape::~CompositeShape()
  {
    for (size_t i = 0; i < shapes_; ++i)
    {
      delete shapeptrs_[i];
    }
    delete[] shapeptrs_;
  }

  void CompositeShape::setArray(Shape **arr)
  {
    shapeptrs_ = arr;
  }

  CompositeShape::CompositeShape(CompositeShape &&comp_shp)
  {
    shapes_ = comp_shp.shapes_;
    capacity_ = comp_shp.capacity_;
    shapeptrs_ = comp_shp.shapeptrs_;
    comp_shp.setArray(nullptr);
  }

  CompositeShape &CompositeShape::operator=(const CompositeShape &comp_shp)
  {
    if (&comp_shp != this)
    {
      Shape **arr = new Shape*[comp_shp.capacity_];
      for (size_t i = 0; i < comp_shp.capacity_; ++i)
      {
        arr[i] = comp_shp.shapeptrs_[i];
      }
      delete[] shapeptrs_;
      shapeptrs_ = arr;
      shapes_ = comp_shp.shapes_;
      capacity_ = comp_shp.capacity_;
    }
    return *this;
  }

  CompositeShape &CompositeShape::operator=(CompositeShape &&comp_shp)
  {
    if (&comp_shp != this)
    {
      delete[] shapeptrs_;
      shapeptrs_ = comp_shp.shapeptrs_;
      comp_shp.shapeptrs_ = nullptr;
    }
    return *this;
  }

  double CompositeShape::getArea(size_t id) const
  {
    return shapeptrs_[id]->getArea();
  }

  rectangle_t CompositeShape::getFrameRect(size_t id) const
  {
    return shapeptrs_[id]->getFrameRect();
  }

  void CompositeShape::move(size_t id, point_t p)
  {
    return shapeptrs_[id]->move(p);
  }

  void CompositeShape::move(size_t id, double dx, double dy)
  {
    return shapeptrs_[id]->move(dx, dy);
  }

  void CompositeShape::scale(size_t id, double k)
  {
    return shapeptrs_[id]->scale(k);
  }

  void CompositeShape::push_back(Shape *shp)
  {
    if (capacity_ == shapes_)
    {
      shapeptrs_ = expandArray(shapeptrs_, capacity_);
      if (shapeptrs_ == nullptr)
      {
        throw std::bad_alloc();
      }
      capacity_ *= 2;
    }
    shapeptrs_[shapes_++] = shp;
  }

  void CompositeShape::pop_back()
  {
    delete shapeptrs_[shapes_ - 1];
    shapeptrs_[shapes_ - 1] = nullptr;
  }

  Shape *CompositeShape::at(size_t id) const
  {
    if (id >= shapes_)
    {
      throw std::logic_error("There is no such element");
    }
    return shapeptrs_[id];
  }

  Shape *CompositeShape::operator[](size_t id) const noexcept
  {
    return shapeptrs_[id];
  }

  bool CompositeShape::empty() const
  {
    if (shapes_ == 0)
    {
      return true;
    }
    return false;
  }

  size_t CompositeShape::size() const
  {
    return shapes_;
  }

  Shape *CompositeShape::clone(size_t id) const
  {
    Shape *figure = shapeptrs_[id];
    try
    {
      Rectangle *shp = dynamic_cast< Rectangle* >(figure);
      Rectangle *shape = new Rectangle(shp->getCQ1(), shp->getCQ2(), shp->getCQ3(), shp->getCQ4());
      return shape;
    }
    catch (const std::bad_cast &e)
    {

    }
    try
    {
      Square *shp = dynamic_cast< Square* >(figure);
      Square *shape = new Square(shp->getRect());
      return shape;
    }
    catch (const std::bad_cast &e)
    {

    }
    try
    {
      ComplexQuad *shp = dynamic_cast< ComplexQuad* >(figure);
      ComplexQuad *shape = new ComplexQuad(shp->getA(), shp->getB(), shp->getC(), shp->getD());
      return shape;
    }
    catch (const std::bad_cast &e)
    {

    }
    return nullptr;
  }

  Shape **expandArray(Shape **arr, size_t capacity)
  {
    Shape **array = nullptr;
    try
    {
      array = new Shape*[capacity * 2];
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
