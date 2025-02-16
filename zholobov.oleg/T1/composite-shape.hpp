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

    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;

    void push_back(Shape* shape);
    void pop_back();
    Shape* at(size_t idx);
    const Shape* at(size_t idx) const;
    Shape* operator[](size_t idx) noexcept;
    const Shape* operator[](size_t idx) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    void clear() noexcept;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy);
    void scale(double k);

    void print(std::ostream& output) const;
    void scale_relative(point_t pos, double scale_factor);

    void swap(CompositeShape& other) noexcept;

  private:
    Shape* items_[max_elem_num];
    size_t items_num_;
  };
}

#endif
