#include "matrixOutput.hpp"

void asafov::outputMatrix(std::ostream& out, const int* mtx, unsigned long long n, unsigned long long m)
{
  out << n << ' ' << m;
  for (unsigned long long i = 0; i < n * m; i++) {
    out << ' ' << mtx[i];
  }
}
