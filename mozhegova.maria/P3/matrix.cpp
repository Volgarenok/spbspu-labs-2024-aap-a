#include "matrix.hpp"
#include <cstring>
#include <cctype>
#include <iostream>

bool mozhegova::isNumber(const char * str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

int ** mozhegova::createMatrix(size_t m, size_t n)
{
  int ** t = new int * [m];
  size_t created = 0;
  try
  {
    for (; created < n; created++)
    {
      t[created] = new int[n];
    }
  }
  catch(const std::bad_alloc & e)
  {
    mozhegova::destroy(t,created);
    throw;
  }
  return t;
}

void mozhegova::destroy(int ** t, size_t m)
{
  for (size_t i; i < m; i++)
  {
    delete[] t[i];
  }
  delete[] t;
}