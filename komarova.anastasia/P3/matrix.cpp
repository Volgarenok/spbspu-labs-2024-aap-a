#include "matrix.h"
#include <fstream>

long int komarova::notanum(const char* st)
{
  char* endptr = nullptr;
  long int numer = std::strtol(st, std::addressof(endptr), 10);
  if (*endptr != '\0')
  {
    throw std::logic_error("First parameter is not a number");
  }
  else if ((numer > 2) || (numer < 1))
  {
    throw std::logic_error("First parameter is out of range");
  }
  return numer;
}
bool komarova::checktri(const int * arr, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      if (arr[(i * m) + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}

std::istream& komarova::input_m(std::istream& input, int * array, size_t size_arr)
{
  for (size_t i = 0; i < size_arr; ++i)
  {
    input >> array[i];
  }
  return input;
}
