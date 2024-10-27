#include "taylor_output.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstring>
void nikonov::stringOutput(const double& x, const double& val, const double& stdval)
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
void nikonov::stringOutput(const double& x, const std::logic_error& e, const double& stdval)
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
