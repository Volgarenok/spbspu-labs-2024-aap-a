#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
namespace kiselev
{
  class CompositeShape
  {
  public:
    CompositeShape(const CompositeShape & cmp);
    CompositeShape(CompositeShape && cmp) noexcept;
    CompositeShape(size_t cap);
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & cmp);
    CompositeShape & operator=(CompositeShape && cmp) noexcept;
    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id) const;
    Shape * at(size_t id);
    Shape * operator[](size_t id) const noexcept;
    Shape * operator[](size_t id) noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k, point_t scale);
    void scale(double k);

  private:
    size_t capacity;
    size_t realSize;
    Shape ** shapes;
    void clear() noexcept;
  };
}
#endif
