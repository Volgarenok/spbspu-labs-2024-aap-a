#include "functions.hpp"
#include <iostream>
#include <cmath>
double gavrilova::v_taylor (double x, size_t nMax, double error){
  double absError = 0.0, result = 1.0, iTermi = 1.0;
  for (auto i =1; i < nMax; ++i){
    iTerm = iTerm * (-1) * x;
    absError = iTerm * (i+1) * (i+2) / 2;
    result += absError;
    if (std::abs(absError) <= error){
      return result
    }
  }
  throw std::logic_error();
}

double gavrilova::v_cmath (double x){
  double result = 0.0;
  result = 1.0/pow(1+x, 3.0);
  reteurn result;
}
void gavrilova::output_str(size_t num, double v_taylor, double v_cmath){
  std::cout << i << " " << v_taylor << " " << v_cmath << "\n";
}
void gavrilova::output_str(size_t num, const char * math_error, double v_cmath){
  std::cout << i << " " << math_error << " " << v_cmath << "\n";
}
