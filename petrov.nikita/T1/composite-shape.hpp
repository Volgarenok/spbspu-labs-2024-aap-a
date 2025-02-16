#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace petrov
{
  struct CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs) noexcept;
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs) noexcept;
    void swap(CompositeShape & rhs) noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & concrete_point);
    void move(double dx, double dy);
    void scale(double k);
    void push_back(Shape * shp);
    void pop_back() noexcept;
    Shape * at(size_t id);
    const Shape * at(size_t id) const;
    Shape * operator[](size_t id);
    const Shape * operator[](size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    size_t capacity_;
    size_t size_of_vector_;
    Shape ** shapes_vector_;
  };
}
#endif
