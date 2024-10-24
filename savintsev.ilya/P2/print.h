#include <iostream>
#include <iomanip>
#include "function.h"
#include <cstring>
#ifndef PRINT_H
#define PRINT_H

namespace savintsev {

  struct Interval {
  double begin = 0.;
  double end = 0.;
  };

  Interval readInterval();

  size_t len(double b, double a);
  double roundN(double value, size_t n);

  void printBorder(size_t variation, size_t * w);
  void printLine(double columnNum, size_t * w, size_t k);
  void printLine(size_t * w);
  void printSheetOfLines(Interval, size_t k);
}

#endif
