#ifndef ALL_H
#define ALL_H
#include <iostream>
#include <cmath>
namespace tkach
{
  void output_table(double start, double end, size_t maxkolvo,  const double error, const double step);
  void output_row(double start, size_t maxkolvo, const double error);
  double teylor_row(double start, size_t maxkolvo, const double error);
  double stdmath(double coshx); 
} 
#endif
