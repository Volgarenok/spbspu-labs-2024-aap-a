#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <fstream>

namespace komarova
{
  long int notanum(const char* st);
  bool checktri(const int * arr, size_t m);
  std::istream& input_m(std::istream & input, int * array, size_t size_m);
}
#endif
