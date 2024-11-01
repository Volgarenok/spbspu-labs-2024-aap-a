#include "matrix.hpp"

std::istream& abramov::input_matrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    in >> mtx[i];
    ++read;
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

void abramov::output_matrix(std::ostream &out, int *mtx, size_t m)
{
  for (size_t i = 0; i < m * m; ++i)
  {
    out << mtx[i] << " ";
  }
  out << "\n";
}
