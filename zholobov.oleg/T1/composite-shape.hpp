#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"

namespace zholobov {
  class CompositeShape {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other);
    ~CompositeShape();

    void push_back(Shape* shp);
    void pop_back();
    Shape* at(size_t id) const;
    Shape* operator[](size_t id) const;
    bool empty() const;
    size_t size() const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy);
    void scale(double k);

  private:
    Shape* items[10000];
    size_t items_num;
  };
}

#endif
