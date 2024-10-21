#ifndef FUNCTION_H
#define FUNCTION_H
#include <cstddef>
const char* errorm = "<MATH ERROR>";
const size_t sec_column = std::strlen(errorm);
const size_t oth_column = 10;
namespace kiselev
{
  double f(double x, size_t k, double error);
  double sqr_unox(double x);
  void output_table(double number, size_t k, double error);
}
