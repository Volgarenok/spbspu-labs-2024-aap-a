#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <fstream>

namespace beshimow {
  std::istream& input(std::istream& inputFile, int* arr, size_t m);
  bool lwrTriMtx(const int* arr, size_t m);
}

#endif
