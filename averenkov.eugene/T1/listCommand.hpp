#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace averenkov
{
  void destroy(Shape** list, size_t count);
  void scaleList(Shape** list, size_t count, point_t scale_center, double factor);
  double calculateTotalArea(const Shape* const* list, size_t count);
  void printFigure(const Shape* shap);
  void printList(const Shape* const* list, size_t count);
}

#endif
