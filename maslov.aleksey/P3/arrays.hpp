#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <cstddef>
#include <fstream>

namespace maslov
{
  int * convert(const int* const* t, size_t m, size_t n, int * array);
  int** createMatrix(size_t m, size_t n);
  void destroyMatrix(int** theMatrix, size_t m);
  std::istream & inputMatrix(std::istream & in, 
      int** t, size_t m, size_t n, size_t & read);
  //int cntLocMax();
  // void outputMatrix(std::ostream &out);
}

#endif