#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace abramov
{
  struct CompositeShape
  {
    CompositeShape(const CompositeShape &comp_shp);
    CompositeShape(CompositeShape &&comp_shp) noexcept;
    CompositeShape(size_t capacity);
    ~CompositeShape();
    CompositeShape &operator=(const CompositeShape &comp_shp);
    CompositeShape &operator=(CompositeShape &&comp_shp) noexcept;
    Shape *operator[](size_t id) noexcept;
    const Shape *operator[](size_t id) const noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    void move(const point_t &p);
    void move(double dx, double dy);
    void scale(double k);
    void scaleUnsafe(double k);
    void pushBack(Shape *shp);
    void popBack() noexcept;
    Shape *at(size_t id);
    const Shape *at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape *clone() const;
  private:
    size_t shapes_;
    size_t capacity_;
    Shape **shapeptrs_;

    void swap(CompositeShape &comp_shp) noexcept;
    void deleteShapes(size_t k);
  };

  using Composite = CompositeShape;
}
#endif
