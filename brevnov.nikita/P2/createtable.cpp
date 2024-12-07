#include "createtable.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstring>
#include <iomanip>
#include "teylor.hpp"

void brevnov::outputing(double left, double right, size_t k)
{
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  for (auto i = left; i < right; i += step)
  {
    tablecheck(i, k, error);
    std::cout<< "\n";
  }
  tablecheck(right, k, error);
  std::cout<< "\n";
}

void brevnov::tablecheck(double i, size_t k, double error)
{
  const char * errorsum = "<MATH ERROR>";
  const size_t second_width = std::strlen(errorsum);
  constexpr size_t usually_width = 10;
  constexpr size_t usu = usually_width;
  const size_t snd = second_width;
  std::cout << std::fixed << std::setw(usu) << i;
  std::cout << " ";
  try
  {
    std::cout << std::fixed << std::setw(snd) << brevnov::f(i,k,error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(snd) << "<MATH ERROR>";
  }
  std::cout << " " << std::fixed << std::setw(usu) << std::atan(i);
}
