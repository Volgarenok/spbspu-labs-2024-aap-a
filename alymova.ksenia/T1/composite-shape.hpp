#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
namespace alymova
{
  struct Shape;

  struct CompositeShape final
  {
    CompositeShape();
    CompositeShape(const CompositeShape& comp_shape);
    CompositeShape(CompositeShape&& comp_shape);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& comp_shape);
    CompositeShape& operator=(CompositeShape&& comp_shape);
    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;

    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(const point_t& point) noexcept;
    void move(double shift_x, double shift_y) noexcept;
    void scale(double ratio);
    void unsafeScale(double ratio) noexcept;

    void push_back(Shape* shp);
    void pop_back() noexcept;
    Shape* at(size_t id);
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    void swap(CompositeShape& other) noexcept;
    void do_default(CompositeShape& comp_shape) noexcept;
    void clear(size_t size_now) noexcept;
    void clear() noexcept;

    size_t size_, capacity_;
    Shape** shapes_;

  };
}
#endif
