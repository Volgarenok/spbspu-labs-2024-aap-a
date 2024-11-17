#ifndef MATRIXPROCESSING_HPP
#define MATRIXPROCESSING_HPP

#include <iostream>
namespace krylov
{
  std::istream & inputMatrix(std::istream & in, int* matrix, size_t rows, size_t columns);
  size_t getColumnWithMaxEquals(const int* matrix, size_t rows, size_t columns);
}

#endif


