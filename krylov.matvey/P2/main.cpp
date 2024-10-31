#include <iostream>
#include "calculateMathValues.hpp"
#include "outputTable.hpp"
int main()
{
  double left_border = 0.0, right_border = 0.0;
  size_t max_terms_number = 0;

  std::cin >> left_border >> right_border >> max_terms_number;
  if (!std::cin || (left_border < -1) || (right_border > 1) || (left_border > right_border))
  {
    std::cerr << "Incorrect input!\n";
    return 1;
  }
  constexpr double error = 0.001;
  constexpr double step = 0.05;
  krylov::tableOutput(left_border, right_border, max_terms_number, step, error);
}
