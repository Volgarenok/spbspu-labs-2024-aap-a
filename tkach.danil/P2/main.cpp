#include <cstddef>
#include <iostream>
#include <cmath>
#include "all.h"

int main()
{
  const double error = 0.001;
  const double step = 0.1;
  std::cout << step << "\n";
  double start = 0.0, end = 0.0;
  size_t maxkolvo = 0;
  std::cin >> start >> end >> maxkolvo;
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
  if ((start<-1) || (start>1) ||  (end>1) || (end<-1))
  {
    std::cerr << "Incorrect input of interval value\n";
    return 1;
  }
  if (start > end)
  {
    std::cerr << "Incorrect input of interval: start need to be first\n";
    return 1;
  }
  if (maxkolvo <= 0)
  {
    std::cerr << "Incorrect value of number of terms\n";
    return 1;
  }
  tkach::output_table(start, end, maxkolvo, error,  step);
  tkach::output_row(end, maxkolvo, error);
  return 0;
}
