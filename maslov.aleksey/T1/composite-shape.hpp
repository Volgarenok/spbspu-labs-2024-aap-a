#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace maslov
{
  struct CompositeShape final
  {
    CompositeShape();
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs) noexcept;
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs) noexcept;
    ~CompositeShape();
    Shape * operator[](size_t id);
    const Shape * operator[](size_t id) const;
    void push_back(Shape * shp);
    void pop_back();
    const Shape * at(size_t id) const;
    Shape * at(size_t id);
    bool empty() const noexcept;
    size_t size() const noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double dx, double dy);
    void scaleWithoutCheck(double k);
    void scale(double k);
   private:
    size_t size_;
    Shape * shapeArray_[10000];
    void cloneArray(const CompositeShape & rhs);
    void fillArrayAndDeleteRhs(CompositeShape & rhs);
    void swap(CompositeShape & rhs) noexcept;
  };
}

#endif
