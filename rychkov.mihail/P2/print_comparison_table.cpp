#include "print_comparison_table.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "taylors_row.hpp"

void rychkov::comparison::printTable(double left, double right, double step, size_t maxDepth, double absError)
{
  std::cout << std::fixed;
  for(double i = left; i <= right - step/2; i += step)
  {
    printLine(i, maxDepth, absError);
  }
  printLine(right, maxDepth, absError);
}
void rychkov::comparison::printLine(double x, size_t maxDepth, double absError)
{
  std::cout << std::setw(8) << std::setprecision(2) << x << ' ';
  std::cout << std::setprecision(4);
  try
  {
    std::cout << std::setw(12) << calcUnoDivSqr(x, maxDepth, absError);
  }
  catch (const std::runtime_error& e)
  {
    std::cout << "<MATH ERROR> ";
  }
  std::cout << std::setw(12) << calcUnoDivSqrWithStd(x) << '\n';
}
