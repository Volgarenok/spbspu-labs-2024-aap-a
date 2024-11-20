#include "table.h"
#include <fstream>

bool komarova::notanum(char * st)
{
  for (size_t i = 0; st[i] != '\0'; ++i)
  {
    if (st[i] < '0' || st[i] > '9')
    {
      return true;
    }
  }
  return false;
}
void komarova::checktri(std::ostream& output, int * arr, size_t m)
{
  bool k = true;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = i + 1; j < m; ++j)
    {
      if (arr[(i * m) + j] != 0)
      {
        k = false;
        break;
      }
    }
  }
  if ((k == true) && (m > 1))
  {
    output << "true";
  }
  else
  {
    output << "false";
  }
}

std::istream& komarova::input_m(std::istream& input, int * array, size_t size_arr)
{
  for (size_t i = 0; i < size_arr; ++i)
    {
      input >> array[i];
    }
  return input;
}
