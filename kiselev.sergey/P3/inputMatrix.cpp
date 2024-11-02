#include "inputMatrix.h"
#include <stdexcept>
void kiselev::inputMatrix(std::ifstream& in, int* array, size_t m, size_t n)
{
  if (in.good())
  {
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        in >> array[i * n + j];
      }
    }
  }
  else if (in.eof())
  {
    throw std::logic_error("The file is empty\n");
  }
  else
  {
    throw std::invalid_argument("The contents are not a two-dimensional array\n");
  }
}
