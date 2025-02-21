#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace dribas
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& shp);
    CompositeShape(CompositeShape&& shp) noexcept;
    CompositeShape & operator=(const CompositeShape & shp);
    CompositeShape & operator=(CompositeShape && shp) noexcept;
    ~CompositeShape();

    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    size_t size() const noexcept;
    void move(point_t point);
    void move(double x, double y);
    void scale(double ratio);

    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id);
    Shape * operator[](size_t id);
    const Shape* at(size_t id) const;
    const Shape * operator[](size_t id) const;
    bool empty() const noexcept;
  private:
    Shape* shapes_[10000];
    size_t size_;
  };
}
#endif
