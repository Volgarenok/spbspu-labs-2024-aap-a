#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace tkach
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    virtual ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double add_to_x, double add_to_y) noexcept;
    virtual void move(const point_t& point_to_move) noexcept;
    virtual void scale(double multiplier);
    void push_back(Shape* shp);
    void pop_back();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;
    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    size_t size_;
    Shape** shapes_;
  };
}

#endif
