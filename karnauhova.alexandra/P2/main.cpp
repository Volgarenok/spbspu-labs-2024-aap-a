#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "namespace.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;
  
  const double error = 0.001;
  const double step = 0.05;
  karnauhova::output_table(left, right, step, k, error, 13);  
}
