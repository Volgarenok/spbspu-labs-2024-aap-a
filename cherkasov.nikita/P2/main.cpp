#include <iostream>
#include <stdexcept>
#include <cstring>
#include "taylor_f.h"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  const char* errormsg = "<MATH ERROR>";
  const size_t column_width = std::strlen(errormsg);
  const size_t others_columns = 10;
  std::cout << "Enter the begining and end the interval and max number:\n";

  if (!(std::cin >> left >> right >> k))
  {
    std::cerr << "Input error. Exiting.\n";
    return 1;
  }
  if (right < left || left < -1 || right > 1)
  {
    std::cerr << "check interval boundaries.\n";
    return 1;
  }

  for (double x = left; x <= right; x += step)
  {
    cherkasov::processValue(x, k, error, column_width, others_columns);
  }

  return 0;
}
