#include <iostream>
#include "taylor.h"

int main()
{
  double begin = 0.0, end = 0.0;
  size_t k = 0;
  std::cin >> begin >> end >> k;
  if (!std::cin)
  {
    std::cerr << "Input Error\n";
    return 1;
  }

  if (begin > end)
  {
    std::cerr << "Incorrect interval\n";
    return 1;
  }

  bool isInDefinitionArea = begin > -1 && end < 1;
  if (isInDefinitionArea == false)
  {
    std::cerr << "Out of definition area\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.05;
  for (auto i = begin; i < end; i += step)
  {
    demehin::output(i, k, error);
  }
  demehin::output(end, k, error);
}
