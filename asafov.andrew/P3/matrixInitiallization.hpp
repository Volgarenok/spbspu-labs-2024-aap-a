#ifndef MATRIXINITIALLIZATION_H
#define MATRIXINITIALLIZATION_H
#include <cstddef>
#include <fstream>
namespace asafov
{
  void initializationMatrixAuto(std::istream& in, int* mtx, size_t& n, size_t& m);
  void initializationMatrixDynamic(std::istream& in, int* mtx, unsigned long long& n, unsigned long long& m);
}
#endif
