#include "arrays.hpp"

std::istream & maslov::inputMatrix(std::istream & in, int** t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      in >> t[i][j];
    }
    ++read;
  }
  return in;
}
int * maslov::convert(const int* const* t, size_t m, size_t n, int * array)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      array[i * n + j] = t[i][j];
    }
  }
  return array;
}
void maslov::destroyMatrix(int** theMatrix, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] theMatrix[i];
  }
  delete[] theMatrix;
}

int** maslov::createMatrix(size_t m, size_t n)
{
  int** theMatrix = new int*[m];
  size_t created = 0;
  try
  {
    for(; created < m; ++created)
    {
      theMatrix[created] = new int[n];
    }
  }
  catch(const std::bad_alloc & e)
  {
    maslov::destroyMatrix(theMatrix, created);
    throw;
  }
  return theMatrix;
}
// void maslov::outputMatrix(std::ostream &out);
