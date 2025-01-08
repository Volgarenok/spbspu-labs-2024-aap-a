#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"
namespace kiselev
{
  class CompositeShape
  {
  public:
    CompositeShape(size_t cap);
    CompositeShape(const CompositeShape & cmp);
    CompositeShape(CompositeShape && cmp) noexcept;
    CompositeShape & operator=(CompositeShape & cmp);
    CompositeShape & operator=(CompositeShape && cmp) noexcept;
    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id) const;
    Shape * operator[](size_t id) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k, point_t scale);
    void scale(double k);
    ~CompositeShape();

  private:
    void clear() noexcept;
    Shape ** shapes;
    size_t capacity;
    size_t realSize;
  };
}
#endif
