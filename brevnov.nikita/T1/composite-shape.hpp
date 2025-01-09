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
    CompositeShape(size_t cus);
    CompositeShape(CompositeShape & cos);
    CompositeShape(CompositeShape && cos) noexcept;
    CompositeShape & operator=(CompositeShape & cos);
    CompositeShape & operator=(CompositeShape && cos) noexcept;
    void add_memory();
    void push_back(Shape * sp);
    void pop_back();
    Shape * at(size_t id);
    Shape * operator[](size_t id) noexcept;
    bool empty() noexcept;
    size_t size() noexcept;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t a) noexcept;
    void move(double dx, double dy) noexcept;
    void scale(double k,  point_t scale) noexcept;
    void scale(double k) noexcept;
    ~CompositeShape();
  private:
    void clear() noexcept;
    Shape ** shapes_;
    size_t capacity_;
    size_t current_size_;
  };
  void print_frame_coordinates(CompositeShape CoSh, std::ostream & out);
}
#endif
