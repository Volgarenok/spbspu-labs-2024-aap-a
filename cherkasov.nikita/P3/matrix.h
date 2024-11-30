#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <fstream>
namespace cherkasov
{
  int readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray, int* matrix);
  int processMatrix(const int* matrix, size_t rows, size_t cols);
  bool lowerTriangul(const int* matrix, size_t rows, size_t cols);
}
#endif
