#include <cstddef>
#include <iostream>
#include <cmath>
#include "all.h"
double TeylorRow(double x, size_t k, double error);

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
  std::cout <<  end << " " <<  maxkolvo << "\n";
  std::cout << TeylorRow(start,10,error) << "\n";
  std::cout << cosh(start) << "\n";
  return 0;
}
