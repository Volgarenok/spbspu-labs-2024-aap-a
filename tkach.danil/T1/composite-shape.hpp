#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace tkach
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double add_to_x, double add_to_y);
    void move(const point_t& point_to_move);
    void scale(double multiplier);
    void doUnsafeScale(double multiplier);
    void pushBack(Shape* shp);
    void popBack();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    size_t size_;
    Shape** shapes_;
    void swap(CompositeShape&) noexcept;
  };
}

#endif
