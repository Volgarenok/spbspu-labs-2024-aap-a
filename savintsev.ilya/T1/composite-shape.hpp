#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace savintsev
{
  class CompositeShape
  {
  public:
    ~CompositeShape();
    CompositeShape();
    CompositeShape(size_t n);

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double x, double y);
    void scale(double k);

    void push_back(Shape * shp);
    void pop_back();
    Shape * at(size_t id);
    Shape * at(size_t id) const;
    Shape * operator[](size_t id);
    bool empty();
    size_t size() const;
  private:
    void destroyShapes(Shape ** shps);
    Shape ** lst_;
    size_t amt_;
    size_t cap_;
  };
}
#endif
