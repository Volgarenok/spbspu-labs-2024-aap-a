#include "matrix.hpp"

std::istream& abramov::input_Matrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    if (in >> mtx[i])
    {
      ++read;
    }
  }
  return in;
}

int *abramov::toSquare(int *mtx, size_t m, size_t n, size_t &count)
{
  int *matrix = nullptr;
  size_t k = 0;
  if (n >= m)
  {
    matrix = new int[m * m];
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < m; ++j)
      {
        matrix[k++] = mtx[n * i + j];
      }
    }
    count = m;
  }
  else
  {
    matrix = new int [n * n];
    for (size_t i = 0; i < n; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        matrix[k++] = mtx[n * i + j];
      }
    }
    count = n;
  }
  return matrix;
}

void abramov::transform_Matrix(int *mtx, size_t count)
{
  int iBegin = count;
  int iEnd = 0;
  int jBegin = 0;
  int jEnd = count;
  size_t amount = count * count;
  int value = 0;
  size_t counter = 0;
  while(counter < amount)
  {
    for(int i = --iBegin; i >= iEnd; --i)
    {
    ++counter;
    mtx[i * count + jBegin] -= ++value;
    }
    for(int i = ++jBegin; i < jEnd; ++i)
    {
    ++counter;
    mtx[iEnd * count + i] -= ++value;
    }
    for(int i = ++iEnd; i < iBegin; ++i)
    {
    ++counter;
    mtx[i * count + jEnd - 1] -= ++value;
    }
    for(int i = --jEnd; i >= jBegin; --i)
    {
    ++counter;
    mtx[iBegin * count + i] -= ++value;
    }
  }
}

void abramov::output_Matrix(std::ostream &out, int *mtx, size_t m)
{
  out << m << " " << m << " ";
  for (size_t i = 0; i < m * m; ++i)
  {
    out << mtx[i] << " ";
  }
  out << "\n";
}
