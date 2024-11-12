#include "matrix.h"

std::istream& aleksandrov::inputMatrix(std::istream& input, int* array, size_t m, size_t n)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    input >> array[i];
  }
  return input;
}

void aleksandrov::outputMatrix(std::ostream& output, const int* array, size_t m, size_t n)
{
  if (m == 0 || n == 0)
  {
    output << m << " " << n << "\n";
  }
  else
  {
    output << m << " " << n;
    for (size_t i = 0; i < m * n; ++i)
    {
      output << " " << array[i];
    }
    output << "\n";
  }
}

