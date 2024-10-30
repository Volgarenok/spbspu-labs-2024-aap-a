#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace hismatova
{
  double taylorSin(const double& x, const size_t& k);
  void resultsInTable(const double& x, const size_t& k);
  double sinx(const double& x);
}

#endif
