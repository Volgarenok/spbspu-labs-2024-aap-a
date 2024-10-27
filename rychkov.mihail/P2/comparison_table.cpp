#include "comparison_table.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstring>

#include "taylors_series.hpp"

void rychkov::printTable(std::ostream& outstream, double left, double right,
    double step, size_t maxDepth, double absError)
{
  outstream << std::fixed;
  for (double i = left; i <= right - step * 0.1; i += step)
  {
    printLine(outstream, i, maxDepth, absError);
    outstream << '\n';
  }
  printLine(outstream, right, maxDepth, absError);
  outstream << '\n';
}
void rychkov::printLine(std::ostream& outstream, double x, size_t maxDepth, double absError)
{
  constexpr const char* errorMessage = "<MATH ERROR>";
  constexpr size_t xPrecision = 3;
  constexpr size_t resultPrecision = 4;
  constexpr size_t xColumnWidth = xPrecision + 6;
  constexpr size_t resultColumnWidth = std::strlen(errorMessage) + 3;

  outstream << std::setw(xColumnWidth) << std::setprecision(xPrecision) << x << ' ';
  outstream << std::setprecision(resultPrecision) << std::setw(resultColumnWidth);
  try
  {
    outstream << rychkov::formulas::calcUnoDivSqr(x, maxDepth, absError) << ' ';
  }
  catch (const std::runtime_error& e)
  {
    outstream << errorMessage << ' ';
  }
  outstream << std::setw(resultColumnWidth) << rychkov::formulas::calcUnoDivSqrWithStd(x);
}
