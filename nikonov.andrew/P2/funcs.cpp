#include "funcs.hpp"
double nikonov::cos(double x, size_t numberMax, double absError)
{
  double next = (x * x) / 2;
  double result = 1 - next;
  for (size_t i = 1; i < numberMax; i++)
  {
    next *= x*x/((2*i + 1)*(2*i + 2));
    if (i % 2 == 0)
    {
        result += next;
    }
    else
    {
      result -= next;
    }
  }
  if (std::abs(next) > absError)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return result;
}
double nikonov::stdcos(double x)
{
  return std::cos(x);
}
void nikonov::stringOupout(double x, double val, double stdval)
{
  const char* errmsg = "<MATH ERROR>";
  const size_t snd_col_width = std::strlen(errmsg);
  const size_t oth_col_width = 10;

  std::cout << std::setw(oth_col_width) << x;
  std::cout << " ";
  std::cout << std::setw(snd_col_width) << val;
  std::cout << " ";
  std::cout << std::setw(oth_col_width) << stdval;
  std::cout << "\n";
}
void nikonov::stringOupout(double x, const std::logic_error& e, double stdval)
{
  const char* errmsg = "<MATH ERROR>";
  const size_t snd_col_width = std::strlen(errmsg);
  const size_t oth_col_width = 10;

  std::cout << std::setw(oth_col_width) << x;
  std::cout << " ";
  std::cout << std::setw(snd_col_width) << e.what();
  std::cout << " ";
  std::cout << std::setw(oth_col_width) << stdval;
  std::cout << "\n";
}
