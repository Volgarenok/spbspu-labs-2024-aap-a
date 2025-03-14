#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace sveshnikov
{
  class CompositeShape final
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &copied_shp);
    CompositeShape(CompositeShape &&copied_shp);
    ~CompositeShape();
    CompositeShape &operator=(const CompositeShape &comp_shp);
    CompositeShape &operator=(CompositeShape &&comp_shp);
    Shape *operator[](size_t id) noexcept;
    const Shape *operator[](size_t id) const noexcept;
    Shape *at(size_t id);
    const Shape *at(size_t id) const;
    void push_back(Shape *shp);
    void pop_back();
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape *clone() const;
    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    void move(point_t p);
    void move(double dx, double dy) noexcept;
    void scale(double k);
    void unsafeScale(double k);

  private:
    size_t size_;
    Shape **shapes_;
    void clear();
    void swap(CompositeShape &rhs) noexcept;
  };
}

#endif
