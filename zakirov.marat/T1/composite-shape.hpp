#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace zakirov
{
  class CompositeShape
  {
  public:
    CompositeShape();
    ~CompositeShape();
    CompositeShape(const CompositeShape & copy);
    CompositeShape(CompositeShape && copy);
    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    void move(const point_t & target);
    void move(double bias_x, double bias_y);
    void scale(double k);
    void push_back(Shape * shapes);
    void pop_back();
    Shape * at(size_t id);
    const Shape * at(size_t id) const;
    Shape * operator[](size_t id) noexcept;
    const Shape * operator[](size_t id) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    static constexpr size_t shapes_size_ = 10000;
    Shape * shapes_[shapes_size_];
    size_t shapes_quantity_;
  };
}

#endif
