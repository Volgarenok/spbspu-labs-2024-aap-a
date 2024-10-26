#include <iostream>
#include <cmath>
#include "functions.h"
double averenkov::lnf(double x)
{
  double result = log(x + sqrt(x * x + 1));
  return result;
}
double averenkov::rightside(double x, size_t k, double error)
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

int main()
{
  try {
    std::cout << averenkov::rightside(0.5, 3, 0.01) << "\n" << averenkov::rightside(0.6, 10, 0.1) << "\n";
    std::cout << averenkov::lnf(0.5) << "\n" << averenkov::lnf(0.6) << "\n";
  }
  catch (const char* error_message)
  {
    std::cout << "<MATH ERROR>";
  };
}
