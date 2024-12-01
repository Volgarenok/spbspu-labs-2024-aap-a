#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <fstream>
namespace cherkasov
{
  int readMatrix(std::istream& inFile, size_t& rows, size_t& cols, bool useFixedArray, int* matrix);
  int processMatrix(const int* matrix, size_t rows, size_t cols);
  bool lowerTriangular(const int* matrix, size_t rows, size_t cols);
}
#endif
