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
    CompositeShape(CompositeShape && rhs);
    CompositeShape(size_t capacity);
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double x, double y);
    void scale(double k);
    void unsafeScale(double k) noexcept;
    CompositeShape * clone() const;
    void unsafeScaleRelativeTo(double k, point_t p) noexcept;
    void printAreaBorders(std::ostream & out);

    void push_back(Shape * shp);
    void pop_back() noexcept;
    const Shape * at(size_t id) const;
    const Shape * operator[](size_t id) const noexcept;
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
