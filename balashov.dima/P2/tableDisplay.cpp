#include "tableDisplay.hpp"
#include <iomanip>
#include <cmath>

void balashov::showRow(const double step,const size_t numberOfСalculations,const double error)
{
  constexpr int deepShow = 5;
  constexpr int deepSetW = 5;
  double x = 0;
  if ((step + 0.0001 > 0) && (step - 0.0001 < 0))
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
    std::cout << std::setprecision(deepShow) << balashov::expTaylor(x, numberOfСalculations, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH ERROR>";
  }
  std::cout << "\t" << exp(x);
}

void balashov::showTable (const double minimumIntervalStep, const double maximumIntervalStep,
   int numberOfСalculations, const double step, const double error)
{
  if(minimumIntervalStep < maximumIntervalStep)
  {
    showRow(minimumIntervalStep, numberOfСalculations,error);
  }
  for (double i = minimumIntervalStep + step; i < maximumIntervalStep; i += step)
  {
    std::cout << "\n";
    showRow(i, numberOfСalculations,error);
  }
}
