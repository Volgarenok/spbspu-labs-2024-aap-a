#ifndef PRINT_H
#define PRINT_H
#include <iostream>

namespace savintsev 
{
  size_t calcWidth(const double * p);
  void printMathInfo(const size_t * w);
  void printBorderEquals(const size_t * w);
  void printBorderMinusPlus(const size_t * w);
  void printMathLine(double x, const size_t * w, size_t k);
  void printMathSheet(double begin, double end, size_t k);
}

#endif
