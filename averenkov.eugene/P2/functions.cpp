#include <iostream>
#include <cmath>
#include "functions.h"
#include <iomanip>
#include <cstring>
double averenkov::lnf(double x)
{
  double result = log(x + sqrt(x * x + 1));
  return result;
}
double averenkov::f(double x, int k, double error)
{
  double next = x;
  double result = x;
  if (k == 1)
  {
    return x;
  }
  for (int i = 2; i < k; ++i)
  {
    next = ( (i - 1) * x * x * next / 2) / (i + 1);
    if (i % 2 == 0)
    {
      result -= next;
    }
    else if (i % 2 == 1)
    {
      result += next;
    }
  }
  if ((result - averenkov::lnf(x)) > error)
  {
    throw "logic_error";
  }
  else if ((result - averenkov::lnf(x)) < (0.0 - error))
  {
    throw "logic_error";
  }
  return result;

}

void averenkov::outline(double x, int k, double error)
{
  std::cout << std::setw(15) << x;
  std::cout << std::setw(15) << averenkov::lnf(x) << " ";
  try {
    std::cout << std::setw(15) << averenkov::f(x, k, error) << "\n";
  }
  catch (const char* error_message)
  {
    std::cout << std::setw(15) << "<MATH ERROR>\n";
  };
}
