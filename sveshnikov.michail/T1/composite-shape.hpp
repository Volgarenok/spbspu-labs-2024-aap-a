#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"
#include <iomanip>

namespace sveshnikov
{
  class CompositeShape final
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &);
    CompositeShape(CompositeShape &&);
    ~CompositeShape();
    CompositeShape operator=(const CompositeShape &);
    CompositeShape operator=(CompositeShape &&);
    Shape *operator[](size_t id) noexcept;
    const Shape *operator[](size_t id) const noexcept;
    Shape *at(size_t id) noexcept;
    const Shape *at(size_t id) const noexcept;
    void push_back(Shape *shp) noexcept;
    void pop_back() noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape *clone() const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy);
    void scale(double k);

  private:
    size_t size_;
    sveshnikov::Shape *shapes_[10000];
    void unsafe_scale(double k);
  };
}

#endif
