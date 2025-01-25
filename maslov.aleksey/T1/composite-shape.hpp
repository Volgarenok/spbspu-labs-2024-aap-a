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
    CompositeShape(CompositeShape && rhs);
    CompositeShape & operator=(const CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape && rhs);
    ~CompositeShape();
    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id);
    Shape * operator[](size_t id);
    bool empty();
    size_t size();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double dx, double dy);
    void scale(double k);
   private:
    size_t size_;
    Shape * shapeArray_[10000];
  };
}

#endif