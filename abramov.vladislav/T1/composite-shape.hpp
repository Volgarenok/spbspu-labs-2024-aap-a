#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace abramov
{
  struct CompositeShape
  {
    double getArea(size_t id) const;
    rectangle_t getFrameRect(size_t id) const;
    void move(size_t id, point_t p);
    void move(size_t id, double dx, double dy);
    void scale(size_t id, double k);
    ~CompositeShape() = default;
    void push_back(Shape *shp);
    void pop_back();
    Shape *at(size_t id) const;
    Shape *operator[](size_t id) const noexcept;
    bool empty() const;
    size_t size() const;
    Shape *clone() const;
  private:
    size_t shapes_;
    size_t capacity_;
    Shape *shapeptrs_;
  };
}
#endif
