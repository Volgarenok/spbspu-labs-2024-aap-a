#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace rychkov
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&& src) noexcept;
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept;

    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;
    Shape* at(size_t id);
    const Shape* at(size_t id) const;

    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t destination) noexcept;
    void move(double deltaX, double deltaY) noexcept;
    void scale(double coef);
    CompositeShape* clone() const;

    size_t size() const noexcept;
    bool empty() const noexcept;
    void push_back(Shape* value);
    void pop_back();
  private:
    Shape** shapes_;
    size_t size_, capacity_;
    static Shape** reallocate(Shape** shapes, size_t oldSize, size_t newSize);
  };
  void scale(CompositeShape& shape, double coef, point_t scaleCenter);
}

#endif
