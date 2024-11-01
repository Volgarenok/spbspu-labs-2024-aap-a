#include "taylor_output.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstring>
#include "taylor_cos.hpp"
void nikonov::stringOutput(double x, double numberMax, double absError)
{
  double stdval = nikonov::stdcos(x);
  constexpr const char* errmsg = "<MATH ERROR>";
  constexpr size_t snd_col_width = std::strlen(errmsg);
  constexpr size_t oth_col_width = 10;
  nikonov::setWidth(std::cout, 2, oth_col_width) << x;
  std::cout << " ";
  try
  {
    double val = nikonov::cos(x, numberMax, absError);
    nikonov::setWidth(std::cout, 6, oth_col_width) << val;
    std::cout << " ";
    nikonov::setWidth(std::cout, 6, oth_col_width) << stdval;
  }
  catch (const std::logic_error& e)
  {
    nikonov::setWidth(std::cout, 6, snd_col_width) << e.what();
    std::cout << " ";
    nikonov::setWidth(std::cout, 6, oth_col_width - 2)  << stdval;
  }
}
std::ostream& nikonov::setWidth(std::ostream& out, size_t num, size_t col_width)
{
  return out << std::fixed << std::setprecision(num) << std::setw(col_width);
}
void nikonov::table_output(double left, double right, double step, double numberMax, double absError)
{
  for (double x = left; x < right; x += step)
  {
    nikonov::stringOutput(x, numberMax, absError);
    std::cout << "\n";
  }
  nikonov::stringOutput(right, numberMax, absError);
  std::cout << "\n";
}
