#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace savintsev
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs) noexcept;
    CompositeShape(size_t capacity);
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs) noexcept;

    double getArea() const;
    rectangle_t getFrameRect() const noexcept;
    rectangle_t safeGetFrameRect() const;
    void move(point_t p);
    void move(double x, double y);
    void scale(double k);
    void unsafeScale(double k) noexcept;
    CompositeShape * clone() const;
    void scaleRelativeTo(double k, point_t p);
    void unsafeScaleRelativeTo(double k, point_t p) noexcept;

    void push_back(Shape * shp);
    void pop_back() noexcept;
    const Shape * at(size_t id) const;
    Shape * at(size_t id);
    const Shape * operator[](size_t id) const noexcept;
    Shape * operator[](size_t id) noexcept;
    bool empty() const;
    size_t size() const;
  private:
    size_t amt_;
    size_t cap_;
    Shape ** lst_;
    void destroy(Shape ** shps, size_t n);
  };

  void printAreaAndBorder(std::ostream & out, const CompositeShape & rhs);
}
#endif
