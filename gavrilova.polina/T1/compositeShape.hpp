#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <stdexcept>

namespace gavrilova {

  class CompositeShape {
  public:
    CompositeShape();
    ~CompositeShape();
    CompositeShape(size_t capacity);
    CompositeShape(const CompositeShape& other);
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    void push_back(Shape* shp);
    void pop_back();
    Shape* operator[](size_t id);
    Shape* at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    void scale(double k);
    void move(double difX, double difY);
    rectangle_t getFrameRect() const;

  private:
    size_t size_;
    size_t capacity_;
    Shape** shapes_;

    void resize(size_t new_capacity);
    void swap(CompositeShape& rhs) noexcept;
  };
}

#endif