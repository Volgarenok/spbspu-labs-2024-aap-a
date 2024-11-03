#include "input_matrix.h"
#include <stdexcept>
#include <fstream>
std::istream & timofeev::input_matrix(std::istream& in, int* matrix, size_t size_matrix)
{
  for (size_t i = 0; i < size_matrix; i++)
  {
    in >> matrix[i];
  }
  return in;
}
