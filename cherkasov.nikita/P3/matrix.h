#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <fstream>
namespace cherkasov
{
  int createMatrix(size_t rows, size_t cols, int*** matrix);
  int fillMatrix(std::ifstream& inFile, size_t rows, size_t cols, int** matrix);
  int readMatrix(const char* inputFile, size_t& rows, size_t& cols, bool useFixedArray, int***);
  void freeMatrix(int** matrix, size_t rows);
  int processMatrix(int** matrix, size_t rows, size_t cols);
  bool lowerTriangul(const int** matrix, size_t rows, size_t cols);
}
#endif
