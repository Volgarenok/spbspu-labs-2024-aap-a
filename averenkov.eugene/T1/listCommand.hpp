#ifndef LIST_DESTROY_HPP
#define LIST_DESTROY_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace averenkov
{
  void destroy(Shape** list, size_t count);
  void scaleList(Shape** list, size_t count, point_t scale_center, double factor);
  double calculateTotalArea(Shape* const * list, size_t count);
  void printList(Shape* const * list, size_t count);
}

#endif
