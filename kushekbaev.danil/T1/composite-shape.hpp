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
    CompositeShape(const CompositeShape& rhs);
    CompositeShape(CompositeShape&& rhs) noexcept;

    ~CompositeShape();

    CompositeShape& operator=(const CompositeShape& rhs);
    CompositeShape& operator=(CompositeShape&& rhs) noexcept;
    CompositeShape* clone() const;
    
    Shape* operator[](size_t id) noexcept;
    const Shape* operator[](size_t id) const noexcept;
    Shape* at(size_t id);
    const Shape* at(size_t id) const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t scalePoint);
    void move(double dx, double dy);
    void scale(double scaleCoeff);
    void push_back(Shape* shp);
    void pop_back();
    bool empty() const noexcept;
    size_t size() const noexcept;
    void scaleEverything(point_t scalePoint, double scaleCoeff);

  private:
    Shape** array_;
    size_t capacity_;
    size_t shapeCounter_;

    Shape** creatingNewArray(Shape** array, size_t old_size, size_t new_size);
    void swap(CompositeShape& rhs);
    void scaleArray(size_t size);
  };
}

#endif
