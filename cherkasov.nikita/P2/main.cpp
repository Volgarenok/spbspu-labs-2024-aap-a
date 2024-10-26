#include <iostream>
#include <stdexcept>
#include "fun.h"
#include <cstring>

  int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 10;
  const double error = 0.001;
  const double step = 0.05;
  const char* errormsg = "<MATH ERROR>";
  const size_t colWidth= std::strlen(errormsg);
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
  for (double x = left; x < right; x += step)
  {
    double Taylor_value;
    try
    {
      Taylor_value = cherkasov::Taylor(x, k, error);
    }
    catch (const std::logic_error&)
      {
        cherkasov::exception();
        std::cout << " ";
        std::cout.width(others_columns);
        std::cout << cherkasov::exp(x);
        std::cout << "\n";
        continue;
      }
    double exp_value = cherkasov::exp(x);
    cherkasov::table(x, Taylor_value, exp_value, colWidth, others_columns);
    }
      try
    {
      double Taylor_value = cherkasov::Taylor(right, k, error);
      double exp_value = cherkasov::exp(right);
      cherkasov::table(right, Taylor_value, exp_value, colWidth, others_columns);
    }
      catch (const std::logic_error&)
    {
      cherkasov::exception();
      std::cout << " ";
      std::cout.width(others_columns);
      std::cout << cherkasov::exp(right);
      std::cout << "\n";
    }
    return 0;
}
