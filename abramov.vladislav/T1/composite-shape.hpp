#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"

namespace abramov
{
  struct CompositeShape
  {
    CompositeShape(size_t capacity);
    CompositeShape(const CompositeShape &comp_shp);
    CompositeShape(CompositeShape &&comp_shp);
    CompositeShape &operator=(const CompositeShape &comp_shp);
    CompositeShape &operator=(CompositeShape &&comp_shp);
    double getArea(size_t id) const;
    rectangle_t getFrameRect(size_t id) const;
    void move(size_t id, point_t p);
    void move(size_t id, double dx, double dy);
    void scale(size_t id, double k);
    ~CompositeShape();
    void push_back(Shape *shp);
    void pop_back();
    Shape *at(size_t id) const;
    Shape *operator[](size_t id) const noexcept;
    bool empty() const;
    size_t size() const;
    Shape *clone(size_t id) const;
    void setArray(Shape **arr);
  private:
    size_t shapes_;
    size_t capacity_;
    Shape **shapeptrs_;
  };

  Shape **expandArray(Shape **arr, size_t capacity);
}
#endif
