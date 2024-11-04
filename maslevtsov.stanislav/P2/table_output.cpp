#include "table_output.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "taylor_series.hpp"

void maslevtsov::stringOutput(double current, size_t numberMax, double absError)
{
  std::cout << std::setprecision(5);
  std::cout << std::fixed;
  std::cout << std::setw(10);
  std::cout << current;
  try
  {
    std::cout << std::setw(15);
    std::cout << maslevtsov::taylorSeries(current, numberMax, absError);
  }
  catch (const std::logic_error &e)
  {
    std::cout << std::setw(15);
    std::cout << "<MATH ERROR>";
  }
  std::cout << std::setw(10);
  std::cout << 1 / (std::sqrt(1 - current * current));
  std::cout << "\n";
}

void maslevtsov::tableOutput(double left, double right, size_t numberMax, double step, double absError)
{
  for (auto i = left; i < right; i += step)
  {
    maslevtsov::stringOutput(i, numberMax, absError);
  }
  maslevtsov::stringOutput(right, numberMax, absError);
}
