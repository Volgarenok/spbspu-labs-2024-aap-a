#include "print_comparison_table.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

#include "taylors_row.hpp"

void rychkov::comparison_utilities::printTable(double left, double right, double step, size_t maxDepth, double absError)
{
  std::cout << std::fixed;
  for(double i = left; i <= right - step * 0.1; i += step)
  {
    printLine(i, maxDepth, absError);
  }
  printLine(right, maxDepth, absError);
}
void rychkov::comparison_utilities::printLine(double x, size_t maxDepth, double absError)
{
  constexpr const char* errorMessage = "<MATH ERROR>";
  constexpr size_t xFieldPrecision = 3;
  constexpr size_t resultFieldsPrecision = 4;
  constexpr size_t xFieldWidth = 6 + xFieldPrecision;
  constexpr size_t resultFieldsWidth = strlen(errorMessage) + 3;

  std::cout << std::setw(xFieldWidth) << std::setprecision(xFieldPrecision) << x << ' ';
  std::cout << std::setprecision(resultFieldsPrecision) << std::setw(resultFieldsWidth);
  try
  {
    std::cout << rychkov::formulas::calcUnoDivSqr(x, maxDepth, absError) << ' ';
  }
  catch (const std::runtime_error& e)
  {
    std::cout << errorMessage << ' ';
  }
  std::cout << std::setw(resultFieldsWidth) << rychkov::formulas::calcUnoDivSqrWithStd(x) << '\n';
}
