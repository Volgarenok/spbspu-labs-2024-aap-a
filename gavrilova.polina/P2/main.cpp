#include <iostream>
#include "functions.hpp"
#include <cmath>

int main()
{
  double begin = 0.0, end = 0.0;
  size_t nMax = 0;
  constexpr double STEP = 0.01;
  constexpr double ERROR = 0.00001;
  constexpr char STRMATHERROR [15] = "<MATH ERROR>";

  std::cin >> begin >> end >> nMax;
  if ((!std::cin) || (begin > end) || (begin <= -1) || (end >= 1)){
    return 1;
  }
  for (double i = begin; i <  end; i += STEP){
    double value_Taylor = 0.0 , value_cmath = 0.0;
    value_cmath = gavrilova::v_cmath(i);
    try{
      value_Taylor = gavrilova::v_taylor(i, nMax, ERROR);
      gavrilova::output_str(i, value_Taylor, value_cmath);
      std::cout << "\n";  
 } catch (const std::logic_error & e) {
      gavrilova::output_str(i, STRMATHERROR, value_cmath);
      std::cout << "\n";
    }
  }
  double end_value_Taylor = 0.0;
  double end_value_cmath = 0.0;
  end_value_cmath = gavrilova::v_cmath(end);
  try{
    end_value_Taylor = gavrilova::v_taylor(end, nMax, ERROR);
    gavrilova::output_str(end, end_value_Taylor, end_value_cmath);
    std::cout << "\n";
  } catch (const std::logic_error & e) {
    gavrilova::output_str(end, STRMATHERROR, end_value_cmath);
    std::cout << "\n";
  }
}
