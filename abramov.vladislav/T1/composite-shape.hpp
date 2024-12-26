#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace abramov
{
  struct CompositeShape
  {
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy);
    void scale(double k);
    ~CompositeShape() = default;
    void push_back(Shape * shp);
    void pop_back();
    Shape *at(size_t id) const;
    Shape *operator[](size_t id) const;
    bool empty() const;
    size_t size() const;
    Shape *clone() const;
  private:
    size_t shapes;
    size_t capacity;
    Shape *shapeptrs;
  };
}
#endif
