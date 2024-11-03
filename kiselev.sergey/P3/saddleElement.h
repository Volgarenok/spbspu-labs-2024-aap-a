#ifndef SEDDLEELEMENT_H
#define SEDDLEELEMENT_H
#include <cstddef>
#include "stddef.h"
namespace kiselev
{
  int saddleElement(int* array, size_t m, size_t n);
  bool isMinInRow(int* array, size_t n, size_t i, size_t j);
  bool isMaxInColumn(int* array, size_t m, size_t n, size_t i, size_t j);
}
#endif
