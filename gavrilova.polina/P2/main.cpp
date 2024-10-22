#include <iostream>
int main()
{
  double begin = 0.0, end = 0.0;
  size_t nMax = 0;
  const step = 0.05;
  const error = 0.001;

  std::cin >> begin >> end >> nMax;
  if (!std::cin || (begin < end) || (begin <= -1) || (end >= 1)){
    return 1
  }
}

