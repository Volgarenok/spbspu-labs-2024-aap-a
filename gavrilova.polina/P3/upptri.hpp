#ifndef UPPTRI_HPP
#define UPPTRI_HPP
#include <istream>
#include <cstddef>
namespace gavrilova
{
  bool checkNumOfArguments(int argc);
  bool checkFirstArgument(unsigned long int num, char * end);
  std::istream & input_matrix(std::istream & in, int * mtx, size_t m, size_t n, size_t & read);
  bool isUpperTriangMtx(int * mtx, size_t m, size_t n);
}
#endif
