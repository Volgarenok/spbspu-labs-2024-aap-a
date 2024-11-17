#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
namespace cherkasov
{
  int** readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray);
  int processMatrix(int** matrix, size_t rows, size_t cols);
  void freeMatrix(int** matrix, size_t rows);
  bool lowerTriangul(int** matrix, size_t rows, size_t cols);
}
#endif
