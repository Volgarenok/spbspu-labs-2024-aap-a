#include "taylor.h"

double hismatova::sinx(const double& x)
{
  return std::sin(x);
}
double hismatova::taylorSin(const double& x, const size_t& k)
{
  const double error = 0.001;
  double result = x;
  double numer = x * x * x;
  double denomin = 6.0;
  for (size_t i = 1; i < k; i++)
  {
    double sign = 1.0;
    if (i % 2 != 0)
    {
      sign = -1.0;
    }
    result = result + sign * numer/denomin;
    denomin = denomin * (denomin + 1) * (denomin + 2);
    numer = numer * x * x;
  }
  if (std::abs(result - hismatova::sinx(x)) > error)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return result;
}
void resultsInTable(double& x, const size_t& k)
{
  double res2 = 0;
  const char* errmsg = "<MATH ERROR>";
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
    std::cout << "\n";
  }
  catch (std::logic_error & e)
  {
    std::cerr << errmsg << std::endl;
  }
}
