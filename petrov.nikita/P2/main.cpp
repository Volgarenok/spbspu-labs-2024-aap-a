#include "petrov_namespace.hpp"
#include <iostream>

int main()
{
  double start = 0.0, end = 0.0;
  size_t max = 0;
  std::cin >> start >> end >> max;
  const double abs_error = 0.001;
  const double step = 0.05;
  for (auto i = start; i < end; i += step)
  {
    std::cout << i;
    std::cout << " ";
    std::cout << petrov::calculateByTailor(i, max, abs_error);
    std::cout << " ";
    std::cout << petrov::calculateBySTD(i);
    std::cout << "\n";
  }
  std::cout << end;
  std::cout << " ";
  std::cout << petrov::calculateByTailor(end, max, abs_error);
  std::cout << " ";
  std::cout << petrov::calculateBySTD(end);
  std::cout << "\n";
}
