#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"

namespace zholobov {

  constexpr const size_t max_elem_num = 10000;

  class CompositeShape {
  public:
    CompositeShape() noexcept;
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    ~CompositeShape();

    CompositeShape& operator=(CompositeShape&& other) noexcept;

    void push_back(Shape* shape);
    void pop_back();
    Shape* at(size_t idx) const;
    Shape* operator[](size_t idx) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy);
    void scale(double k);

  private:
    Shape* items_[max_elem_num];
    size_t items_num_;
  };
}

#endif
