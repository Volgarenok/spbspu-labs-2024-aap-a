#include "matrix.h"
#include <iostream>
#include <cmath>

std::istream & savintsev::inputMtx(std::istream & in, int * t, size_t m, size_t n)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    in >> t[i];
  }
  return in;
}

void savintsev::outputMtx(std::ostream & out, const int * t, size_t m, size_t n)
{
  for (size_t i = 0; (i + 1) < (m * n); ++i)
  {
    out << t[i] << ' ';
  }
  if (m * n != 0)
  {
    out << t[m * n - 1];
  }
}

void savintsev::transformMtx(int * t, size_t m, size_t n)
{
  size_t mMid = m / 2 + m % 2;
  size_t nMid = n / 2 + n % 2;
  for (size_t k = 0; k < std::min(mMid, nMid); ++k)
  {
    for (size_t i = k; i < (m - k); ++i)
    {
      for (size_t j = k; j < (n - k); ++j)
      {
        t[j + n * i] += 1;
      }
    }
  }
}

void savintsev::processMtx(std::istream & in, std::ostream & out, int * table, int m, int n)
{
    if (!savintsev::inputMtx(in, table, m, n))
    {
        std::cout << "File text is invalid\n";
        return;
    }
    savintsev::transformMtx(table, m, n);
    out << (m * n == 0 ? "" : " ");
    savintsev::outputMtx(out, table, m, n);
}
