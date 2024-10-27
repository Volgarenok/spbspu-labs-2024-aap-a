#include "comparison_table.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

#include "taylors_series.hpp"

void rychkov::comparison_utilities::printTable(double left, double right,
    double step, size_t maxDepth, double absError)
{
  std::cout << std::fixed;
  for (double i = left; i <= right - step * 0.1; i += step)
  {
    printLine(i, maxDepth, absError);
    std::cout << '\n';
  }
  printLine(right, maxDepth, absError);
  std::cout << '\n';
}
void rychkov::comparison_utilities::printLine(double x, size_t maxDepth, double absError)
{
  constexpr const char* errorMessage = "<MATH ERROR>";
  constexpr size_t xPrecision = 3;
  constexpr size_t resultPrecision = 4;
  constexpr size_t xColumnWidth = xPrecision + 6;
  constexpr size_t resultColumnWidth = std::strlen(errorMessage) + 3;

  std::cout << std::setw(xColumnWidth) << std::setprecision(xPrecision) << x << ' ';
  std::cout << std::setprecision(resultPrecision) << std::setw(resultColumnWidth);
  try
  {
    std::cout << rychkov::formulas::calcUnoDivSqr(x, maxDepth, absError) << ' ';
  }
  catch (const std::runtime_error& e)
  {
    std::cout << errorMessage << ' ';
  }
  std::cout << std::setw(resultColumnWidth) << rychkov::formulas::calcUnoDivSqrWithStd(x);
}
