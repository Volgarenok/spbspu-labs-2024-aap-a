#ifndef OUTPUT_H
#define OUTPUT_H
#include "uno_div_cube.h"
namespace mozhegova
{
  void output_row(double i, size_t k, double error);
  void output_table(double left, double right, size_t k, double step, double error);
}

#endif