#ifndef TABLE_DISPLAY_HPP
#define TABLE_DISPLAY_HPP

#include "taylorsRow.hpp"
#include <iostream>

namespace balashov
{
  void showRow(double step, size_t numberOfСalculations, double error);
  void showTable (double minimumIntervalStep, double maximumIntervalStep, int numberOfСalculations,
    double step, double error);
}
#endif
