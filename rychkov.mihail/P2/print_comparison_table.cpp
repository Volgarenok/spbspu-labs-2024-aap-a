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
  constexpr size_t firstColumnWidth = 8;
  constexpr size_t secondColumnWidth = 15;

  std::cout << std::setw(firstColumnWidth) << std::setprecision(2) << x << ' ';
  std::cout << std::setprecision(4);
  try
  {
    std::cout << std::setw(secondColumnWidth) << calcUnoDivSqr(x, maxDepth, absError) << ' ';
  }
  catch (const std::runtime_error& e)
  {
    std::cout << std::setw(secondColumnWidth) << "<MATH ERROR>" << ' ';
  }
  std::cout << std::setw(secondColumnWidth) << calcUnoDivSqrWithStd(x) << '\n';
}
