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

  int len(double b, double a);
  double roundN(double value, int n);

  void printBorder(int b);
  void printLine(double columnNum, int * w, size_t k);
  void printSheetOfLines(Interval, size_t k);
}

#endif
