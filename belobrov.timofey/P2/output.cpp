#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "output.hpp"
#include "f_teylor.hpp"
using namespace belobrov;

void parameters_output(const double& n)
{
  std::cout << std::fixed << std::setprecision(6) << std::setw(10) << n; 
}

void table_out(const double& n, const size_t& k)
{
  try
  {
    double temp = 0;
    temp = f_teylor(n, k);
    parameters_output(n);
    std::cout << " ";
    parameters_output(temp);
    std::cout << " ";
    parameters_output(std::cos(n));
    std::cout << "\n";
  }
  catch(const std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
  }

}

void output(const double& left, const double& right, const double& step, const size_t& k)
{
  for (double i = left; i < right; i += step)
  {
    table_out(i, k);
  }
  table_out(right, k);
}
