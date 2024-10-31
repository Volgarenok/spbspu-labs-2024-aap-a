#include "taylor_output.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstring>
#include "taylor_cos.hpp"
void nikonov::stringOutput(double x, double val, double stdval)
{
  constexpr size_t oth_col_width = 10;
  constexpr const char* errmsg = "<MATH ERROR>";
  constexpr size_t snd_col_width = std::strlen(errmsg);
  std::cout << std::fixed << std::setprecision(2) << std::setw(oth_col_width) << x;
  std::cout << " ";
  std::cout << std::setprecision(6) << std::setw(snd_col_width) << val;
  std::cout << " ";
  std::cout << std::setprecision(6) << std::setw(oth_col_width) << stdval;
}
void nikonov::stringOutput(double x, const std::logic_error& e, double stdval)
{
  constexpr size_t oth_col_width = 10;
  constexpr const char* errmsg = "<MATH ERROR>";
  constexpr size_t snd_col_width = std::strlen(errmsg);
  std::cout << std::fixed << std::setprecision(2) << std::setw(oth_col_width) << x;
  std::cout << " ";
  std::cout << std::setprecision(6) << std::setw(snd_col_width) << e.what();
  std::cout << " ";
  std::cout << std::setprecision(6) << std::setw(oth_col_width) << stdval;
}
void nikonov::table_output(double x, double val, double numberMax, double absError, bool e = 0)
{
  double stdval = nikonov::stdcos(x);
  try
  {
    double val = nikonov::cos(x, numberMax, absError);
    nikonov::stringOutput(x, val, stdval);
    std::cout << "\n";
  }
  catch (const std::logic_error& e)
  {
    nikonov::stringOutput(x, e, stdval);
    std::cout << "\n";
  }
}
