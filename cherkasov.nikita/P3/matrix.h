#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <fstream>
namespace cherkasov
{
  bool readMatrix(std::istream& in, size_t& rows, size_t& cols, int* matrix);
  int processMatrix(const int* matrix, size_t rows, size_t cols);
  bool lowerTriangular(const int* matrix, size_t rows, size_t cols);
}
#endif
