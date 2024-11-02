#include "inputMatrix.h"
std::istream& kiselev::inputMatrix(
    std::istream& in, int* array, size_t m, size_t n, int& count_read)
{
  if (in.good())
  {
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        in >> array[i * n + j];
        count_read++;
      }
    }
  }
  return in;
}
