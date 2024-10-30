#include "brevnov.hpp"
#include <cstring>
#include <iomanip>
#include <cmath>

void tablecheck(size_t i, const size_t k, const double error)
{
  constexpr char * errorsum = "<MATH ERROR>";
  constexpr size_t second_width = std::strlen(errorsum);
  constexpr size_t usually_width = 10;
  constexpr size_t usu = usually_width;
  constexpr size_t snd = second_width;
  std::cout << std::fixed << std::setw(usu) << i;
  std::cout << " ";
  try
  {
    std::cout << std::fixed << std::setw(snd) << brevnov::f(i,k,error);
  } 
  catch (std::logic_error & e)
  {
    std::cout << std::setw(snd) << "<MATH ERROR>";
  }
  std::cout << " " << std::fixed << std::setw(usu) << std::atan(i); 
  std::cout<< "\n";
}