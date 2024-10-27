#include <iostream>
#include "taylorrow.h"
#include "tableoutput.h"

int main()
{
  constexpr double error = 0.001;
  constexpr double step = 0.1;
  double start = 0, end = 0;
  size_t maxamount = 0;
  std::cin >> start >> end >> maxamount;
  if (std::cin.eof())
  {
    std::cerr << "Input Error: not all in input\n";
    return 1;
  }
  if (!std::cin.good())
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  if ((start < -1) || (start > 1) ||  (end > 1) || (end < -1))
  {
    std::cerr << "Incorrect input of interval value\n";
    return 1;
  }
  if (start > end)
  {
    std::cerr << "Incorrect input of interval: start need to be first\n";
    return 1;
  }
  if (maxamount <= 0)
  {
    std::cerr << "Incorrect value of number of terms\n";
    return 1;
  }
  tkach::outputTable(start, end, maxamount, error, step);
  tkach::outputRow(end, maxamount, error);
  std::cout << "\n";
  return 0;
}
