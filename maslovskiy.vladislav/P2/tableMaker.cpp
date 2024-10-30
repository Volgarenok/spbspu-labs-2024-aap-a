#include "tableMaker.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

void standartiseOut(const double num)
{
  std::cout << std::fixed << std::setprecision(6) << std::setw(10) << num;
}

void tableOut(const double num, const size_t k, const double error)
{
  try
  {
    double temp = 0;
    temp = maslovskiy::teilorCos(num, k, error);
    standartiseOut(num);
    std::cout << " ";
    standartiseOut(temp);
    std::cout << " ";
    standartiseOut(std::cos(num));
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void maslovskiy::tableMaker(const double left, const double right, const double step, const size_t k, const double error)
{
  for (double i = left; i < right; i += step)
  {
    tableOut(i, k, error);
    std::cout << "\n";
  }
  tableOut(right, k, error);
}
