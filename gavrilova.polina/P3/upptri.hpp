#ifndef UPPTRI_HPP
#define UPPTRI_HPP
#include <istream>
#include <cstddef>
namespace gavrilova
{
  int checkNumOfArguments(int argc);
  int checkFirstArgument(unsigned long int num, const char * end);
  std::istream & input_matrix(std::istream & in, int * mtx, size_t m, size_t n, size_t & read);
  int output_matrix(std::ostream & out, std::istream & in, const int * mtx, size_t read, size_t m, size_t n, unsigned long int num);
  bool isUpperTriangMtx(const int * mtx, size_t m, size_t n);
}
#endif
