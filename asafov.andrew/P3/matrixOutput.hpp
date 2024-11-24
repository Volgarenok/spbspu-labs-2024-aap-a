#ifndef MATRIX_OUTPUT_H
#define MATRIX_OUTPUT_H
#include <cstddef>
#include <fstream>
namespace asafov
{
  void outputMatrix(std::ostream& out, const int* mtx, const unsigned long long n, const unsigned long long m);
}
#endif
