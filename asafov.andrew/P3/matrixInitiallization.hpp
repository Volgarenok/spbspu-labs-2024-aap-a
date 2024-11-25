#ifndef MATRIXINITIALLIZATION_H
#define MATRIXINITIALLIZATION_H
#include <fstream>
namespace asafov
{
  void initializationMatrix(std::istream& in, int* mtx, unsigned long long& n, unsigned long long& m);
  int* initializationMatrix(std::istream& in, unsigned long long& n, unsigned long long& m);
}
#endif
