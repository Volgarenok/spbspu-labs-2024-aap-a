#include "matrix.h"
#include <fstream>

bool komarova::isanum(const char * st)
{
  char* endptr = nullptr;
  if (*endptr != '\0')
  {
    return false;
  }
  return true;
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
