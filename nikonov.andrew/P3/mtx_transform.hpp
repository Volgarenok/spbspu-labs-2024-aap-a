#ifndef MTX_TRANSFORM_HPP
#define MTX_TRANSFORM_HPP
#include <iostream>
#include <cstdlib>
namespace nikonov
{
  std::istream& readMatrix(std::istream& input, int* mtx, size_t m, size_t n, size_t& read);
  void printMatrix(std::ostream& output, int* mtx, size_t m, size_t n);
  void spiralMtxReduction(int* mtx, size_t m, size_t n);
}
#endif
