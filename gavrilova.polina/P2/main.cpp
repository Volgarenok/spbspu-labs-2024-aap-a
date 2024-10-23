#include <iostream>
#include "functions.hpp"
#include <cmath>
int main()
{
  double begin = 0.0, end = 0.0;
  size_t nMax = 0;
  const double STEP = 0.05;
  const double ERROR = 0.001;

  std::cin >> begin >> end >> nMax;
  if (!std::cin || (begin < end) || (begin <= -1) || (end >= 1)){
    return 1
  }
  for (auto i = begin; i <  end; i += STEP){
    double value_Taylor = 0.0 , value_cmath = 0.0;
    try{
      value_Taylor = gavrilova::v_taylor(i, nMax, ERROR);
    } catch (const std::logic_error & e) {
      std::cout << "<MATH ERROR>";
    }
    value_cmath = gavrilova::v_cmath(i);
    gavrilova::output_str(i, value_Taylor, value_cmath);
  }
  double end_value_Taylor = 0.0
  try{
      end_value_Taylor = gavrilova::v_taylor(end, nMax, ERROR);
    } catch (const std::logic_error & e) {
      std::cout << "<MATH ERROR>";                                          }
  gavrilova::output_str(end, v_taylor(end, nMax, ERROR), v_cmath(end));
}

