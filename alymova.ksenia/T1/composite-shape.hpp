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
    CompositeShape(const CompositeShape&& comp_shape);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& comp_shape);
    CompositeShape& operator=(const CompositeShape&& comp_shape);
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
    void copyArray(const Shape* const* other_shapes);
    void swap(CompositeShape& copy) noexcept;
    void do_null(size_t id) noexcept;
    void clear(Shape** shapes) noexcept;

    size_t size_, capacity_;
    Shape** shapes_;

  };
}
#endif
