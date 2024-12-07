#ifndef IOMATRIX_HPP
#define IOMATRIX_HPP
#include <cstddef>
#include <iostream>

namespace shabalin
{
  void inputMatrix(std::istream& input, int* matrix, size_t countOfElements);
  void outputMatrix(std::ostream& output, const int* matrix, size_t rows, size_t cols);
}

#endif
