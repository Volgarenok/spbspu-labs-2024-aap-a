#ifndef TABLE_H
#define TABLE_H
#include <cstddef>
#include <fstream>

namespace komarova
{
  bool notanum(char * st);
  void checktri(std::ostream & output, int * arr, size_t m);
  std::istream& input_m(std::istream & input, int * array, size_t size_m);
}
#endif
