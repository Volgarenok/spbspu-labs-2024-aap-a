#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <cstddef>
#include <fstream>

namespace maslov
{
  std::istream &inputMatrix(std::istream &in, int *matrix,
      size_t rows, size_t columns, size_t &read);
  size_t findLocalMaximum(const int *array, size_t rows, size_t columns);
}

#endif
