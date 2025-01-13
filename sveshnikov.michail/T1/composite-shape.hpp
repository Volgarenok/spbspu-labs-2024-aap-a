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
    CompositeShape(const CompositeShape &&);
    ~CompositeShape();
    CompositeShape operator=(const CompositeShape &);
    CompositeShape operator=(const CompositeShape &&);
    Shape *operator[](size_t id) noexcept;
    const Shape *operator[](size_t id) const noexcept;
    Shape *at(size_t id) noexcept;
    const Shape *at(size_t id) const noexcept;
    void push_back(const Shape *shp) noexcept;
    void pop_back() noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape *clone() const;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double k);

  private:
    size_t size_;
    sveshnikov::Shape *shapes_[10000];
    virtual void unsafe_scale(double k) = 0;
  };
}

#endif
