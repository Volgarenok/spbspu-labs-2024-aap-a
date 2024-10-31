#include "matrix.h"
#include <iostream>

namespace savintsev
{
  std::istream& inputMtx(std::istream& in, int* t, size_t m, size_t n, size_t& count)
  {
    for (size_t i = 0; i < (m * n); ++i)
    {
      in >> t[i];
      ++count;
    }
    return in;
  }
  void outputMtx(std::ostream& out, int* t, size_t m, size_t n)
  {
    out << m << ' ' << n << ' ';
    for (size_t i = 0; i < (m * n - 1); ++i)
    {
      out << t[i] << ' ';
    }
    out << t[m * n - 1] << '\n';
  }
  void transformMtx(int* t, size_t m, size_t n)
  {
    size_t mMid = m / 2 + m % 2;
    size_t nMid = n / 2 + n % 2;
    for (size_t k = 0; k < (mMid > nMid ? nMid : mMid); ++k)
    {
      size_t iBegin = 0 + k;
      size_t iEnd = m - k;
      size_t jBegin = 0 + k;
      size_t jEnd = n - k;
      for (size_t i = iBegin; i < iEnd; ++i)
      {
        for (size_t j = jBegin; j < jEnd; ++j)
        {
          t[j + n * i] += 1;
        }
      }
    }
  }
}
