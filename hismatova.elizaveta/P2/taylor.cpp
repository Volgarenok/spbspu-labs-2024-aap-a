#include "taylor.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

const char* errmsg = "<MATH ERROR>";
double hismatova::sinx(const double& x)
{
  return std::sin(x);
}
double hismatova::taylorSin(const double& x, const size_t& k)
{
  const double error = 0.001;
  double result = x;
  double numer = result;
  double denomin = 1.0;
  for (size_t i = 1; i < k; i++)
  {
    numer = numer * x * x;
    denomin = denomin * (2 * i) * (2 * i + 1);
    double sign = 1.0;
    if (i % 2 != 0)
    {
      sign = -1.0;
    }
    result = result + sign * numer/denomin;
  }
  if (std::abs(result - hismatova::sinx(x)) > error)
  {
    throw std::logic_error(errmsg);
  }
  return result;
}
void hismatova::resultsInTable(const double& x, const size_t& k)
{
  double res2 = 0;
  try
  {
    res2 = hismatova::taylorSin(x, k);
    const size_t snd = std::strlen(errmsg);
    const size_t oth = 10;
    std::cout << std::setw(oth) << x;
    std::cout << " ";
    std::cout << std::setw(snd) << res2;
    std::cout << " ";
    std::cout << std::setw(oth) << hismatova::sinx(x);
  }
  catch (std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
  }
}
