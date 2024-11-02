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
  for (size_t i = 0; i < m; i++)
  {
    delete[] t[i];
  }
  delete[] t;
}

std::istream & mozhegova::inputMatrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (in >> t[i][j])
      {
        read++;
      }
      else
      {
        return in;
      }
    }
  }
  return in;
}

int * mozhegova::convert(int ** t, size_t m, size_t n)
{
  int * v = new int[n * m];
  size_t k = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      v[k] = t[i][j];
      k++;
    }
  }
  return v;
}

bool mozhegova::uppTriMtx(int * v, size_t m, size_t n)
{
  if (m != n)
  {
    return false;
  }
  size_t step = 0;
  for (size_t k = m + 1; k < n * m; k += m + 1)
  {
    step++;
    for (size_t i = 0; i < step; i++)
    {
      if (v[k - i] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
