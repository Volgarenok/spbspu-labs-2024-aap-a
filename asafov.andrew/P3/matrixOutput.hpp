#ifndef MATRIX_OUTPUT_H
#define MATRIX_OUTPUT_H
#include <fstream>
namespace asafov
{
  void outputMatrix(std::ostream& out, const int* mtx, unsigned long long n, unsigned long long m);
}
#endif
