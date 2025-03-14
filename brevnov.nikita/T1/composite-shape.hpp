#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include <ostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace brevnov
{
  class CompositeShape
  {
  public:
    CompositeShape(const CompositeShape & cos);
    CompositeShape(CompositeShape && cos) noexcept;
    CompositeShape(size_t cus);
    ~CompositeShape();
    CompositeShape & operator=(const CompositeShape & cos);
    CompositeShape & operator=(CompositeShape && cos) noexcept;
    const Shape * operator[](size_t id) const noexcept;
    Shape * operator[](size_t id) noexcept;
    void add_memory();
    void push_back(Shape * sp);
    void pop_back();
    const Shape * at(size_t id) const;
    Shape * at(size_t id);
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t a) noexcept;
    void move(double dx, double dy) noexcept;
    void scale(double k, point_t scale);
    void scale(double k);
    friend void print_frame_coordinates(const CompositeShape& CoSh, std::ostream & out);
  private:
    Shape ** shapes_;
    size_t capacity_;
    size_t current_size_;
    void clear() noexcept;
  };
  void print_frame_coordinates(const CompositeShape& CoSh, std::ostream & out);
  void clearShape(Shape ** shapes, size_t i);
}
#endif
