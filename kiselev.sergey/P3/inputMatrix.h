#ifndef INPUTMATRIX_H
#define INPUTMATRIX_H
#include <fstream>
namespace kiselev
{
  std::istream& inputMatrix(std::istream& in, int* array, size_t m, size_t n, int& count_read);
}
#endif
