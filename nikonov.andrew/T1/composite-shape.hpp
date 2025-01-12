#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"
namespace nikonov
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(CompositeShape &copy);
    CompositeShape(CompositeShape &&copy);
    ~CompositeShape();
    const Shape *operator[](size_t id) const;
    CompositeShape &operator=(const CompositeShape &another);
    CompositeShape &operator=(CompositeShape &&another);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t &a);
    void move(double x, double y);
    void scale(double k) noexcept;
    void scaleWithCheck(double k);
    void push_back(Shape *newElem);
    void pop_back();
    const Shape *at(size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
  private:
    Shape *shp[10000];
    size_t size_;
  };
}
#endif
