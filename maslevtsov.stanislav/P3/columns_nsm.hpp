#ifndef COLUMNS_NSM_HPP
#define COLUMNS_NSM_HPP

#include <iostream>

namespace maslevtsov
{
  bool isSameElements(const int* const matrix, size_t nRows, size_t nColumns, size_t iColumns);
  size_t countColumnsNSM(const int* const matrix, size_t nRows, size_t nColumns);
}

#endif
