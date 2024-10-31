#ifndef PRINT_H
#define PRINT_H
#include <cstddef>

namespace savintsev
{
  struct Triple
  {
    size_t x = 0;
    size_t y = 0;
    size_t z = 0;
  };
  size_t calcWidth(const double * p);
  void printMathInfo(Triple w);
  void printBorderEquals(Triple w);
  void printBorderMinusPlus(Triple w);
  void printMathLine(double x, Triple w, size_t k);
  void printMathSheet(double begin, double end, size_t k);
}

#endif
