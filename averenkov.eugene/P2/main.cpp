#include <iostream>
#include <cmath>
#include "functions.h"
#include <iomanip>
#include <cstring>

int main()
{
  const double step = 0.05;
  const double error = 0.01;
  double left = 0.0;
  double right = 0.0;
  int k = 0;
  std::cin >> left >> right >> k;
  if (!std::cin || left < -1 || right > 1 || left > 1 || right < -1 || right < left) {
    std::cerr << "INCORRECT INPUT";
    return 1;
  }
  for (double i = left; i <= right; i += step) {
    averenkov::outline(i, k, error);
    std::cout << "\n";
  }
  averenkov::outline(right, k, error);
}
