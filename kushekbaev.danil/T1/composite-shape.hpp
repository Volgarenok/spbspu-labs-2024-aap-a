#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace kushekbaev
{
  class CompositeShape
  {
  public:
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs);
    ~CompositeShape();

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t Z);
    void move(double dx, double dy);
    void scale(double V);

    void push_back(Shape* shp);
    void pop_back() noexcept;
    Shape* at(size_t id) const;
    Shape* operator[](size_t id) const noexcept;
    bool empty() const;
    size_t size() const;

  private:
    Shape** creatingNewArray(Shape** array, size_t old_size, size_t new_size);
    Shape** array_;
    size_t shapeCounter_;
    size_t capacity_;
  };
}

#endif
