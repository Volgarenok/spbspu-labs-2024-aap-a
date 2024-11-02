#include "create_matrix.hpp"
#include <cctype>

int* karnauhova::ct_matrix(size_t m,size_t n, int way){
  if (way == 2)
  {
    int* matrix2 = nullptr;
    try
    {
      matrix2 = new int[m*n];
    }
    catch(const std::bad_alloc &e)
    {
      delete[] matrix2;
      throw;
    }
    return matrix2;
  }
  else
  {
    int matrix1[10000] = {};
    return matrix1;
  }
}

bool karnauhova::number(char *str)
{
  if (!std::isdigit(str[0]))
  {
    return false;
  }
  size_t x = 1;
  while (str[x]!='\0')
  {
    if (!std::isdigit(str[x]))
    {
      return false;
    }
    x++;
  }
  return true;
}
