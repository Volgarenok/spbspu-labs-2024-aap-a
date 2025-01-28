#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace petrov
{
  struct CompositeShape
  {
  public:
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t concrete_point);
    void move(double dx, double dy);
    void scale();
    void push_back(Shape * shp);
    void pop_back() noexcept;
    Shape * at(size_t id);
    const Shape * at(size_t id) const;
    Shape * operator[](size_t id);
    const Shape * operator[](size_t id) const;
    bool empty() const noexcept;
    size_t size() const noexcept;
    CompositeShape(CompositeShape & rhs);
    CompositeShape & operator=(CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs) noexcept;
    CompositeShape & operator=(CompositeShape && rhs) noexcept;
    ~CompositeShape();
  private:
    size_t capacity_ = 0;
    size_t size_of_vector_ = 0;
    Shape ** shapes_vector_ = nullptr;
  };
}
#endif