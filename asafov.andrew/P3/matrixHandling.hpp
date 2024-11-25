#ifndef MATRIXHANDLING_H
#define MATRIXHANDLING_H
#include <cstddef>
namespace asafov
{
  void handleLftTopClk(int*& mtx, const unsigned long long n, const unsigned long long m);
  unsigned long long handleNumColLsr(const int* mtx, const unsigned long long n, const unsigned long long m);
}
#endif
