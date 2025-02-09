#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace kushekbaev
{
  class CompositeShape
  {
  public:
    CompositeShape(size_t capacity);
    CompositeShape(CompositeShape && rhs);

    ~CompositeShape();

    CompositeShape& operator=(const CompositeShape & rhs);
    Shape* operator[](size_t id) const noexcept;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t scalePoint);
    void move(double dx, double dy);
    void scale(double scaleCoeff);
    void push_back(Shape* shp);
    void pop_back() noexcept;
    Shape* at(size_t id) const;
    bool empty() const;
    size_t size() const;
    void scaleEverything(point_t scalePoint, double scaleCoeff);

  private:
    Shape** array_;
    size_t capacity_;
    size_t shapeCounter_;


    Shape** creatingNewArray(Shape** array, size_t old_size, size_t new_size);
  };
}

#endif
