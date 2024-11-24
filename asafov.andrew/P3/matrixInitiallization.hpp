#ifndef MATRIXINITIALLIZATION_H
#define MATRIXINITIALLIZATION_H
#include <cstddef>
#include <fstream>
namespace asafov
{
  void initializationMatrixAuto(std::istream& in, int* mtx, unsigned long long& n, unsigned long long& m);
  int* initializationMatrixDynamic(std::istream& in, unsigned long long& n, unsigned long long& m);
}
#endif
