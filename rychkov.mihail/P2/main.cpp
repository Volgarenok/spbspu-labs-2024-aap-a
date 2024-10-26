#include <iostream>
#include "taylors_row.hpp"
#include "print_comparison_table.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t depth = 1;
  if (!(std::cin >> left >> right >> depth))
  {
    std::cerr << "bad input\n";
    return 1;
  }
  if (right < left)
  {
    std::cerr << "incorrect interval\n";
    return 1;
  }
  if ((left <= -1.0) || (right >= 1.0))
  {
    std::cerr << "interval are not in the domain of the function\n";
    return 1;
  }
  constexpr double step = 0.05;
  constexpr double absError = 1e-3;
  rychkov::comparison::printTable(left, right, step, depth, absError);
}
