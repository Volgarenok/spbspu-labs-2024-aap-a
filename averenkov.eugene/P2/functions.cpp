#include <iostream>
#include <cmath>
#include "functions.h"
double averenkov::lnf(double x)
{
  double result = log(x + sqrt(x * x + 1));
  return result;
}
double rightside(double x, size_t k, double error)
{
  double next = 1.0;
  double result = x;
  for (auto i = 1; i < k; i++)
  {
    next = ((i - 1) / i) * next * x * x;
    if (i % 2 == 0)
    {
      result == result - next;
    }
    else
    {
      result == result + next;
    }
  }
  return result;
}

int main()
{
  std::cout << averenkov::rightside(3, 2, 0.1) << "\n" << averenkov::rightside(4, 2, 0.1) << "\n";
}
