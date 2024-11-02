#ifndef TITLEMATRIX_H
#define TITLEMATRIX_H
#include <iostream>

namespace duhanina
{
  std::istream & inputMatrix(std::istream & in, int * t, size_t m, size_t n, size_t & read);
  void outputAnswer(std::ostream & out, int * t, size_t m, size_t n);
  bool isDig(char *);
}

#endif
