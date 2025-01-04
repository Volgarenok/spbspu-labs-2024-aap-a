#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace kiselev
{
  class CompositeShape
  {
  public:
    CompositeShape(size_t cap);
    CompositeShape(CompositeShape & cmp);
    CompositeShape(CompositeShape && cmp) noexcept;
    CompositeShape & operator=(CompositeShape & cmp) noexcept;
    CompositeShape & operator=(CompositeShape && cmp) noexcept;
    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id);
    Shape * operator[](size_t id) noexcept;
    bool empty() noexcept;
    size_t size() noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t a) noexcept;
    void move(double dx, double dy) noexcept;
    void scale(double k) noexcept;
  private:
    void clear() noexcept;
    Shape ** shapes;
    size_t capacity;
    size_t realSize;
  };
}
#endif
