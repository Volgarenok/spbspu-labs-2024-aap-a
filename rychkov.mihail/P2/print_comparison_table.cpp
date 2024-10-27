#include "print_comparison_table.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "taylors_row.hpp"

void rychkov::comparison::printTable(double left, double right, double step, size_t maxDepth, double absError)
{
  std::cout << std::fixed;
  for(double i = left; i <= right - step * 0.1; i += step)
  {
    printLine(i, maxDepth, absError);
  }
  printLine(right, maxDepth, absError);
}
void rychkov::comparison::printLine(double x, size_t maxDepth, double absError)
{
  constexpr size_t xFieldWidth = 8;
  constexpr size_t resultFieldWidth = 15;
  constexpr size_t xFieldPrecision = 2;
  constexpr size_t resultFieldPrecision = 4;

  std::cout << std::setw(xFieldWidth) << std::setprecision(xFieldPrecision) << x << ' ';
  std::cout << std::setprecision(resultFieldPrecision) << std::setw(resultFieldWidth);
  try
  {
    std::cout << calcUnoDivSqr(x, maxDepth, absError) << ' ';
  }
  catch (const std::runtime_error& e)
  {
    std::cout << "<MATH ERROR>" << ' ';
  }
  std::cout << std::setw(resultFieldWidth) << calcUnoDivSqrWithStd(x) << '\n';
}
