#include "tableDisplay.hpp"
#include <iomanip>
#include <cmath>


namespace balashov
{
  void showRow(double step, int deepShow, size_t numberOfTerms, double error)
  {
    double x = 0;
    if ((step + 0.001 > 0) && (step - 0.001 < 0))
    {
      x = 0;
    }
    else
    {
      x = step;
    }
    std::cout << std::setw(5) << step;
    std::cout << "\t" << std::setprecision(deepShow) << balashov::EXP_X(x, numberOfTerms,error)<< "\t" << exp(x) << "\n";
  }

  void showTable(double minimumIntervalStep, double maximumIntervalStep,int numberOfTerms, double step, int deepShow, double error)
  {
    for (double i = minimumIntervalStep; i < maximumIntervalStep; i += step)
    {
      showRow(i, deepShow, numberOfTerms,error);
    }
  }
}
