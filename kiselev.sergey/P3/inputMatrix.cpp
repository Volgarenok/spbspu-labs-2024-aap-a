#include "inputMatrix.h"
std::istream& kiselev::inputMatrix(std::istream& in, int* array, size_t m, size_t n, size_t& count_read)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      if (!(in >> array[i * n + j]))
      {
        return in;
      }
      ++count_read;
    }
  }
  return in;
}
