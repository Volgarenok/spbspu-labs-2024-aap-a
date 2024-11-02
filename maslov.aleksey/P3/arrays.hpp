#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <cstddef>
#include <fstream>

namespace maslov
{
  int * convert(const int* const* matrix, size_t rows,
      size_t columns, int * array);
  int** createMatrix(size_t rows, size_t columns);
  void destroyMatrix(int** theMatrix, size_t rows);
  std::istream & inputMatrix(std::istream & in, int** matrix,
      size_t rows, size_t columns, size_t & read);
  //int cntLocMax();
  // void outputMatrix(std::ostream &out);
}

#endif