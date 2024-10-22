#include <iomanip>
#include <cmath>
#include "tableDisplay.hpp"

int main()
{
  double minimumIntervalStep = 0;
  double maximumIntervalStep = 0;
  size_t numberOfTerms = 0;
  std::cin >> minimumIntervalStep >> maximumIntervalStep >> numberOfTerms;

  const double step = 0.05;
  const int deepShow = 4;
  const double error = 0.001;

  showTable(minimumIntervalStep, maximumIntervalStep, numberOfTerms, step, deepShow, error);

  return 0;
}
