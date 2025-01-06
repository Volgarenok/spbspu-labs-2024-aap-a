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
    CompositeShape(CompositeShape &&comp_shp) noexcept;
    CompositeShape &operator=(const CompositeShape &comp_shp);
    CompositeShape &operator=(CompositeShape &&comp_shp) noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    rectangle_t getFrameRect(size_t id) const noexcept;
    void move(point_t p) noexcept;
    void move(double dx, double dy) noexcept;
    void scale(double k);
    ~CompositeShape();
    void push_back(Shape *shp);
    void pop_back();
    Shape *at(size_t id);
    Shape *at(size_t id) const;
    Shape *operator[](size_t id) noexcept;
    Shape *operator[](size_t id) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    Shape *clone() const;
    size_t getShapes_() const noexcept;
  private:
    size_t shapes_;
    size_t capacity_;
    Shape **shapeptrs_;
  };

  Shape **expandArray(Shape **arr, size_t capacity);
}
#endif
