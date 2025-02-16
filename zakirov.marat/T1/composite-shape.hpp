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
    CompositeShape(const CompositeShape & copy);
    CompositeShape(CompositeShape && copy) noexcept;
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & copy);
    CompositeShape & operator=(CompositeShape && copy) noexcept;
    Shape * operator[](size_t id) noexcept;
    const Shape * operator[](size_t id) const noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    void move(const point_t & target);
    void move(double bias_x, double bias_y);
    void scale(double k) noexcept;
    void scaleWithCheck(double k);
    void push_back(Shape * shapes);
    void pop_back();
    Shape * at(size_t id);
    const Shape * at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    static constexpr size_t shapes_size_ = 10000;
    Shape * shapes_[shapes_size_];
    size_t shapes_quantity_;
  };

  void scale_full_composition(CompositeShape & shapes, const point_t & target, double k);
  void scale_check_full_composition(CompositeShape & shapes, const point_t & target, double k);
  void clear_shapes(Shape ** shapes, size_t quantity);
}

#endif
