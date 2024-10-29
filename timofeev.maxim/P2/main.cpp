#include "arctanTaylor.h"
#include <iostream>

int main()
{
  double start = 0;
  double end = 0;
  size_t number_max = 0;
  constexpr double abs_error = 0.005;
  constexpr double step = 0.02;

  std::cout << "Enter the start, end, number_max: ";
  std::cin >> start >> end >> number_max;

  if (std::cin.fail())
  {
    std::cerr << "inpur error" << "\n";
    return 1;
  }

  if (numberMax <= 0)
  {
    std::cerr << "The maximum number of terms must be a positive integer" << "\n";
    return 11;
  }

  if (start >= end)
  {
    std::cerr << "The beginning of the interval should be less than the end of the interval" << "\n";
    return -1;
  }

  timofeev::matrix_output(start, end, number_max, abs_error, step);
  return 0;
}
