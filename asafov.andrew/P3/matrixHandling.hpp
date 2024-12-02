#ifndef MATRIXHANDLING_H
#define MATRIXHANDLING_H
#include <cstddef>
namespace asafov
{
  void handleLftTopClk(int*& mtx, unsigned long long n, unsigned long long m);
  unsigned long long handleNumColLsr(int* mtx, unsigned long long n, unsigned long long m);
}
#endif
