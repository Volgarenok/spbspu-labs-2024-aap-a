#include "matrix.hpp"

const char *abramov::isCorrect(char *str, int &int_argv1)
{
  if (str[0] == '\0')
  {
    return "Fisrt parameter is not a number\n";
  }
  int_argv1 = std::atoi(str);
  if (str[1] != '\0' && !std::isdigit(str[1]))
  {
    return "First parameter is not a number\n";
  }
  else if (str[1] != '\0' && std::isdigit(str[1]))
  {
    return "First parameter is out of range or not a number\n";
  }
  else if (str[1] == '\0' && (int_argv1 > 2 || int_argv1 < 1))
  {
    return "First parameter is out of range\n";
  }
  return "\0";
}

std::istream& abramov::inputMatrix(std::istream &in, int *mtx, size_t m, size_t n, size_t &read)
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

int *abramov::fillMatrix(const int *mtx, size_t m, size_t n, size_t &count)
{
  int *matrix = nullptr;
  matrix = new int[m * n];
  size_t k = 0;
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      matrix[k++] = mtx[n * i + j];
    }
  }
  count = m;
  return matrix;
}

int *abramov::toSquare(const int *mtx, size_t m, size_t n, size_t &count)
{
  if (n >= m)
  {
    return abramov::fillMatrix(mtx, m, n, count);
  }
  else
  {
    return abramov::fillMatrix(mtx, n, n, count);
  }
}

int *abramov::getMatrix(std::istream &in, int *matrix, size_t m, size_t n, size_t &read, size_t &count)
{
  if (!abramov::inputMatrix(in, matrix, m, n, read) || read != m * n)
  {
    throw std::invalid_argument("Wrong input\n");
  }
  int *new_mtx = nullptr;
  new_mtx = abramov::toSquare(matrix, m, n, count);
  return new_mtx;
}

void abramov::spiralChangeMatrix(int *mtx, size_t count)
{
  int iBegin = count;
  int iEnd = 0;
  int jBegin = 0;
  int jEnd = count;
  size_t amount = count * count;
  int value = 0;
  size_t counter = 0;
  while (counter < amount)
  {
    for (int i = --iBegin; i >= iEnd; --i)
    {
      ++counter;
      mtx[i * count + jBegin] -= ++value;
    }
    for (int i = ++jBegin; i < jEnd; ++i)
    {
      ++counter;
      mtx[iEnd * count + i] -= ++value;
    }
    for (int i = ++iEnd; i < iBegin; ++i)
    {
      ++counter;
      mtx[i * count + jEnd - 1] -= ++value;
    }
    for (int i = --jEnd; i >= jBegin; --i)
    {
      ++counter;
      mtx[iBegin * count + i] -= ++value;
    }
  }
}

void abramov::outputMatrix(std::ostream &out, const int *mtx, size_t m)
{
  out << m << " " << m;
  for (size_t i = 0; i < m * m; ++i)
  {
    out << " " << mtx[i];
  }
  out << "\n";
}
