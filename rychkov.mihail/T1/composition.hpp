#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include <cstddef>
#include "shape.hpp"

namespace rychkov
{
  namespace composition
  {
    Shape** push_back(Shape** shapes, size_t& size, size_t& nAllocated, Shape* value);
    Shape** allocate(size_t size);
    Shape** reallocate(Shape** shapes, size_t nAllocated, size_t newSize);
    void deallocate(Shape** shapes, size_t size);
    double getArea(const Shape*const* shapes, size_t size) noexcept;
    rectangle_t getFrameRect(const Shape*const* shapes, size_t size) noexcept;
    void move(Shape*const* shapes, size_t size, point_t destination) noexcept;
    void move(Shape*const* shapes, size_t size, double deltaX, double deltaY) noexcept;
    void scale(Shape*const* shapes, size_t size, double coef);
  }
}

#endif
