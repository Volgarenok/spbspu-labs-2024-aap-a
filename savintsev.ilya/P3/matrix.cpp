#include "matrix.h"
#include <iostream>
#include "mymath.h"

namespace savintsev
{
  std::istream & inputMtx(std::istream & in, int * t, size_t m, size_t n, size_t & count)
  {
    for (size_t i = 0; i < (m * n); ++i)
    {
      in >> t[i];
      ++count;
    }
    return in;
  }

  void outputMtx(std::ostream & out, int * t, size_t m, size_t n)
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

  void transformMtx(int * t, size_t m, size_t n)
  {
    size_t mMid = m / 2 + m % 2;
    size_t nMid = n / 2 + n % 2;
    for (size_t k = 0; k < minSizet(mMid, nMid); ++k)
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
}
