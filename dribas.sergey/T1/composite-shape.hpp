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
    CompositeShape(CompositeShape&& shp);
    ~CompositeShape();
    Shape * operator[](size_t id);  

    double getArea() const;
    rectangle_t getFrameRect() const;
    void push_back(Shape * shp);
    Shape * at(size_t id) const;
    void pop_back();
    bool empty() const;
    size_t size() const;
    void move(point_t point);
    void move(double x, double y) ;
    void scale(double ratio);
  private:
    Shape* shapes_[10000];
    size_t size_;
  };
}
#endif