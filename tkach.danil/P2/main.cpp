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
  double start = 0, end = 0, maxkolvo=0;
  std::cin >> start >> end >> maxkolvo;
  std::cout <<  end << " " <<  maxkolvo << "\n";
  std::cout << TeylorRow(start,10,error) << "\n";
  std::cout << cosh(start) << "\n";
}
