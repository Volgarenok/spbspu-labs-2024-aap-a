#include "sinh_taylor_calculator.hpp"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdexcept>

void kushekbaev::printResult(double value, size_t snd, size_t oth, size_t max_members, double error)
{
  constexpr const char * errormsg = "<MATH ERROR>";
  try
  {
    std::cout << std::setw(snd) << kushekbaev::taylorCalc(value, max_members, error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << std::setw(snd) << errormsg;
  }
  std::cout << " " << std::setw(oth) << kushekbaev::sinhCalc(value);
}
