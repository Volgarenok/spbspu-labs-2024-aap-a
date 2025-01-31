#ifndef KIZHIN_T1_COMPOSITE_SHAPE_HPP
#define KIZHIN_T1_COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  class CompositeShape
  {
  public:
    CompositeShape(size_t = 0);
    CompositeShape(const CompositeShape&);
    CompositeShape(CompositeShape&&) noexcept;
    ~CompositeShape();

    CompositeShape& operator=(const CompositeShape&);
    CompositeShape& operator=(CompositeShape&&) noexcept;

    Shape* operator[](size_t) noexcept;
    const Shape* operator[](size_t) const noexcept;

    size_t size() const noexcept;
    bool empty() const noexcept;
    Shape** data() const noexcept;
    rectangle_t getFrameRect() const;
    double getArea() const;
    CompositeShape clone() const;

    const Shape* at(size_t) const;
    Shape* at(size_t);

    void move(const point_t&);
    void move(double, double);
    void scale(double);
    void push_back(Shape*);
    void pop_back();

  private:
    Shape** begin_;
    Shape** end_;
    Shape** end_cap_;

    void throw_out_of_range() const;
    void resize(size_t);
    void swap(CompositeShape&) noexcept;
    void clear() noexcept;
  };
}

#endif

