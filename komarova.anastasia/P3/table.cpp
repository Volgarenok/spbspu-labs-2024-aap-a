#include "table.h"

bool komarova::nechislo(char * st)
{
  for (int i = 0; st[i] != '\0'; ++i)
  {
    if (st[i] < '0' || st[i] > '9')
    {
      return true;
    }
  }
  return false;
}
void komarova::checktri(std::ostream & output, int * arr, int m)
{
  bool k = true;
  for (int i = 0; i < m; ++i)
  {
    for (int j = i + 1; j < m; ++j)
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

void komarova::input_m(std::istream & input, int * array, int size_m)
{
  for (int i = 0; i < size_arr; ++i)
    {
      input >> array[i];
    }
  return input;
}
