#include "calculate_sinh.hpp"
#include <iostream>

void petrov::outputTable(double start, double end, size_t max, double error, double step)
{
  std::cout << "========================================\n";
  std::cout << "|    Arg    |  CalcW/Tail  | CalcW/STD |\n";
  std::cout << "========================================\n";
  for (size_t i = start; i < end; i += step)
  {
    petrov::outputFirstColumn(i);
    petrov::outputSecondColumn(i, max, error);
    petrov::outputThirdColumn(i);
  }
  petrov::outputFirstColumn(end);
  petrov::outputSecondColumn(end, max, error);
  petrov::outputThirdColumn(end);
  std::cout << "========================================\n";
}

