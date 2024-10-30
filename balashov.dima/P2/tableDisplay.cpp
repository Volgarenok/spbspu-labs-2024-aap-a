#include "tableDisplay.hpp"
#include <iomanip>
#include <cmath>
#include <iostream>

void balashov::showRow(const double step, const size_t numberOfСalculations, const double error)
{
  constexpr double errorRate = 0.00001;
  constexpr int deepShow = 5;
  constexpr int deepSetW = 5;
  double x = 0;

  if ((step + errorRate > 0) && (step - errorRate < 0))
  {
    x = 0;
  }
  else
  {
    x = step;
  }

  std::cout << std::setw(deepSetW) << x <<  "\t";
  try
  {
    std::cout << std::setprecision(deepShow) << expTaylor(x, numberOfСalculations, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << "\t" << exp(x);
}

void balashov::showTable(const double minimumIntervalStep, const double maximumIntervalStep,
   const int numberOfСalculations, const double step, const double error)
{
  constexpr double errorRate = 0.00001;
  if (minimumIntervalStep < maximumIntervalStep)
  {
    showRow(minimumIntervalStep, numberOfСalculations, error);
  }
  for (double i = minimumIntervalStep + step; i < maximumIntervalStep + errorRate; i += step)
  {
    std::cout << "\n";
    showRow(i, numberOfСalculations, error);
  }
  std::cout << "\n";
  showRow(maximumIntervalStep, numberOfСalculations, error);
}
