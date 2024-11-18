#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <fstream>

namespace abramov
{
  const char *isCorrect(char *str, int &int_argv1);
  int *getMatrix(std::istream &in, int *matrix, size_t m, size_t n, size_t &read, size_t &count);
  std::istream &inputMatrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read);
  int *fillMatrix(const int *mtx, size_t m, size_t n, size_t &count);
  int *toSquare(const int *mtx, size_t m, size_t n, size_t &count);
  void spiralChangeMatrix(int *mtx, size_t count);
  void outputMatrix(std::ostream &out, const int *mtx, size_t m);
}
#endif
