#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
namespace kiselev
{
  class CompositeShape
  {
  public:
    CompositeShape(const CompositeShape& cmp);
    CompositeShape(CompositeShape&& cmp) noexcept;
    CompositeShape(size_t cap);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& cmp);
    CompositeShape& operator=(CompositeShape&& cmp) noexcept;
    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;
    void pushBack(Shape* shp);
    void popBack();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    CompositeShape* clone() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k, point_t scale);
    void scale(double k);

  private:
    size_t capacity_;
    size_t realSize_;
    Shape** shapes_;
    void clear(size_t size) noexcept;
    void swap(CompositeShape& cmp) noexcept;
    void resize(size_t newSize);
  };
}
#endif
