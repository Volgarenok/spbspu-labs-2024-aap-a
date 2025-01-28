#ifndef LIST_DESTROY_HPP
#define LIST_DESTROY_HPP
#include "shape.hpp"
#include "rectanglepoints.hpp"
#include <cstddef>
#include <iostream>

namespace averenkov
{
  void destroy(Shape** list, size_t count);
  void scaleList(Shape** list, size_t count, point_t scale_center, double factor);
  double calculateTotalArea(Shape** list, size_t count);
  void printList(Shape** list, size_t count);
}

#endif
