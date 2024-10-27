#include "taylor.hpp"
#include <cmath>
#include <stdexcept>
#include <cstddef>

double dribas::getTaylor(double x, size_t koll, double error)
{
  double member = 1;
  double result = member;

  for (size_t i = 2; i <= koll ; i += 1){
    member = (((i * ( i + 1)) / 2) * x);
    x *= x;
    if (i % 2 != 0){
      result += member;
    }else{
      result -= member;
    }
    if (std::abs(member) < error){
      return result;
    }
  }
  if (std::abs(member) < error){
    return result;
  }
  throw std::logic_error("<MATH ERROR>");
}

double dribas::getCmathValue(double x)
{
  return 1 / (std::pow(x + 1, 3));
}
