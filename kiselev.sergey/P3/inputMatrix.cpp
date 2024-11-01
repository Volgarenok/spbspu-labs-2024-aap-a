#include "inputMatrix.h"
void kiselev::inputMatrix(std::ifstream& in, char* array, size_t m, size_t n)
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
}
