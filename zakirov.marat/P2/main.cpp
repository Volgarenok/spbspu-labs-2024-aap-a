#include <iostream>
#include "FindingTylor.hpp"
#include "CreatingTables.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t addition_depth = 0;
  std::cin >> left >> right >> addition_depth;

  if (!std::cin)
  {
    std::cerr << "<INPUT_ERROR>" << "\n";
    return 1;
  }

  constexpr double kError = 0.001;
  constexpr double kStep = 0.05;

  if ((left <= -1) || (right >= 1) || (left > right))
  {
    std::cerr << "<INTERVAL_ERROR>" << "\n";
    return 1;
  }

  zakirov::tylor_table(left, right, addition_depth, kStep, kError);
}
