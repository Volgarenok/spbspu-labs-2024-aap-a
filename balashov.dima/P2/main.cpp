#include <cmath>
#include "tableDisplay.hpp"

int main()
{
  double minimumIntervalStep = 0;
  double maximumIntervalStep = 0;
  size_t numberOfTerms = 0;
  std::cin >> minimumIntervalStep >> maximumIntervalStep >> numberOfTerms;
  if(std::cin.eof())
  {
    std::cerr << "Eof\n";
    return 1;
  }
  else if(std::cin.fail())
  {
    std::cerr << "Fail\n";
    return 1;
  }
  const double step = 0.05;
  const int deepShow = 4;
  const double error = 0.001;

  balashov::showTable(minimumIntervalStep, maximumIntervalStep, numberOfTerms, step, deepShow, error);
  balashov::showRow(maximumIntervalStep, deepShow, numberOfTerms, error);
  return 0;
}
