#ifndef TABLE_H
#define TABLE_H
#include <cstddef>
#include <fstream>

namespace komarova
{
  bool nechislo(char * st);
  void checktri(std::ostream & output,int * arr, int m);
  std::istream& input_m(std::istream & input, int * array, int size_m);
}
#endif
