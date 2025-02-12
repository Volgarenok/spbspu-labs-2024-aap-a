#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"

namespace gavrilova {

  class CompositeShape {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    CompositeShape(size_t capacity);
    ~CompositeShape();

    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;

    void push_back(Shape* shp);
    void pop_back();

    Shape* at(size_t id);
    const Shape* at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    void scale(double k);
    void move(double difX, double difY) noexcept;
    void move(const point_t& p) noexcept;
    rectangle_t getFrameRect() const;
    double getArea() const noexcept;
  private:
    size_t size_;
    size_t capacity_;
    Shape** shapes_;

    void expand();
    void resize(size_t capacity);
    void swap(CompositeShape& rhs) noexcept;
    void clear() noexcept;
  };
}

#endif
