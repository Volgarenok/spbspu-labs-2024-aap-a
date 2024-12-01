#ifndef MATRIX_H
#define MATRIX_H


#include <string>
namespace cherkasov
{
  bool readMatrix(const char* inputFile, int**& matrix, int& rows, int& cols, bool useFixedArray);
  int processMatrix(int** matrix, int rows, int cols);
  void freeMatrix(int** matrix, int rows);

  bool lowerTriangul(int** matrix, int rows, int cols);
#include <cstddef>
#include <fstream>
namespace cherkasov
{
  int readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray, int* matrix);
  int processMatrix(const int* matrix, size_t rows, size_t cols);
  bool lowerTriangul(const int* matrix, size_t rows, size_t cols);
}
#endif
