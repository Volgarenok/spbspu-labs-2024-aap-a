#include "output.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "f_teylor.hpp"

namespace belobrov
{
  void parameters_output(double n)
  {
    std::cout << std::fixed << std::setprecision(6) << std::setw(10) << n;
  }

  void table_out(double n, size_t k, double error)
  {
    try
    {
      double teylor_result = f_teylor(n,k,error);
      double ln_result = std::log(n+std::sqrt(n * n + 1));

      parameters_output(n);
      std::cout << " ";
      parameters_output(teylor_result);
      std::cout << " ";
      parameters_output(ln_result);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  void output(double left, double right, double step, size_t k, double error)
  {
    for (double i = left; i < right; i += step)
    {
      table_out(i, k, error);
      std::cout << "\n";
    }
    table_out(right, k, error);
  }
}
