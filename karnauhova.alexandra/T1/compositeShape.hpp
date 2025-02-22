#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace karnauhova
{
  class CompositeShape
  {
  public:
    CompositeShape(size_t count);
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    ~CompositeShape();

    void scale(double k);
    void move(double x, double y) noexcept;
    void move(const point_t& t) noexcept;
    rectangle_t getFrameRect() const;
    double getArea() const noexcept;

    void push_back(Shape* shp);
    void pop_back();
    const Shape* at(size_t id) const;
    Shape* at(size_t id);
    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape* clone() const;

    void swap(CompositeShape& other) noexcept;
    void scale_with_check(double k);
    void clear() noexcept;
    void expanse(size_t new_size);
  private:
    size_t count_shapes_;
    size_t size_;
    Shape** shapes_;
  };
}

#endif
