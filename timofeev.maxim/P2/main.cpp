#include <iostream>
#include "arctanTaylor.h"

int main()
{
  double start = 0;
  double end = 0;
  size_t numberMax = 0;
  const double absError = 0.005;
  const double step = 0.02;

  std::cout << "Enter the start, end, numberMax: ";
  std::cin >> start >> end >> numberMax;

  if (std::cin.fail())
  {
    std::cerr << "inpur error" << std::endl;
    return 1;
  }

  if (numberMax <= 0)
  {
    std::cerr << "The maximum number of terms must be a positive integer" << std::endl;
    return 11;
  }

  if (start >= end)
  {
    std::cerr << "The beginning of the interval should be less than the end of the interval" << std::endl;
    return -1;
  }

  timofeev::MatrixOutput(start, end, numberMax, absError, step);
  return 0;
}
