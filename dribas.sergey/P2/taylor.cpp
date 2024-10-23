#include <cmath>
#include "taylor.hpp"
#include <stdexcept>
#include <cstddef>

double dribas::taylor(double x, size_t koll, double error) {
  double result = 1.0;
  double member = 0.0;
  for (size_t i = 2; i<koll ; i += 1) {
   double l = i;
   member = (((l * (l + 1)) / 2) * x);
   x *= x;
   if (i % 2 != 0) {
     result += member;
   }
   else {
     result -= member;
   }
   if ((abs(result - uno_div_cube(x))) < error) {
     return result;
   }
  }
  if ((abs(result - uno_div_cube(x))) < error) {
    return result;
  }
  throw std::logic_error("<MATH ERROR>");
}
double dribas::uno_div_cube(double x) {
  return 1 / (pow(x + 1, 3));
}
