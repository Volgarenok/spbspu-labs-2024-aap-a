#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"
namespace alymova
{
  struct CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& comp_shape);
    CompositeShape(const CompositeShape&& comp_shape);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& comp_shape);
    CompositeShape& operator=(const CompositeShape&& comp_shape);
    double getArea() const noexcept;
    rectangle_t getFrameRect() const noexcept;
    void move(point_t point) noexcept;
    void move(double shift_x, double shift_y) noexcept;
    void scale(double ratio);
    void push_back(Shape* shp);
    void pop_back() noexcept;
    Shape* at(size_t id);
    Shape* operator[](size_t id) noexcept;
    bool empty() noexcept;
    size_t size() noexcept;
    void copyArray(Shape** other_shapes, Shape** shapes_new, bool& copy_success);
    void clear(Shape** shapes) noexcept;
  private:
    size_t size_, capacity_;
    Shape** shapes_;
  };
}
#endif
