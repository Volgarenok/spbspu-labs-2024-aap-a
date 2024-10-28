#ifndef PRINT_H
#define PRINT_H
#include <iostream>

namespace savintsev {

  size_t lenOfSignedFractionalPart(double a);

  void printMathInfo(const size_t * w);
  void printBorderEquals(const size_t * w);
  void printBorderMinusPlus(const size_t * w);
  void printMathLine(double column, const size_t * w, size_t k);
  void printMathSheet(double begin, double end, size_t k);
}

#endif
