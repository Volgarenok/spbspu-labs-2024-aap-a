#include <iostream>
#include <cmath>
#include "tableDisplay.hpp"

int main()
{
  double minimumIntervalStep = 0;
  double maximumIntervalStep = 0;
  int numberOfСalculations = 0;
  std::cin >> minimumIntervalStep >> maximumIntervalStep >> numberOfСalculations;

  if (std::cin.eof())
  {
    std::cerr << "Not enough elements\n";
    return 1;
  }
  else if (std::cin.fail())
  {
    std::cerr << "Invalid element\n";
    return 1;
  }
  else if (minimumIntervalStep < -1 || minimumIntervalStep > 1)
  {
    std::cerr << "The lower limit is set incorrectly\n";
    return 1;
  }
  else if (maximumIntervalStep < -1 || maximumIntervalStep > 1)
  {
    std::cerr << "The upper limit is set incorrectly\n";
    return 1;
  }
  else if (maximumIntervalStep < minimumIntervalStep)
  {
   std::cerr << "The lower limit is greater than the upper limit\n";
   return 1;
  }
  else if (numberOfСalculations <= 0)
  {
   std::cerr << "number of salculations must be greater than 0\n";
   return 1;
  }

  constexpr double step = 0.05;
  constexpr double error = 0.001;

  balashov::showTable(minimumIntervalStep, maximumIntervalStep, numberOfСalculations,step, error);
  std::cout << "\n";
  return 0;
}
