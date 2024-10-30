#include "calculate_sinh.hpp"
#include <iostream>

void petrov::outputTable(double start, double end, size_t max, double error, double step)
{
  std::cout << "========================================\n";
  std::cout << "|    Arg    |  CalcW/Tayl  | CalcW/STD |\n";
  std::cout << "========================================\n";
  for (auto i = start; i < end; i += step)
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

void petrov::outputFirstColumn(double x)
{
  std::cout << "|";
  if (x < 0.0)
  {
    std::cout << " ";
  }
  else
  {
    std::cout << "  ";
  }
  std::cout << x;
  std::cout << " |";
}

void petrov::outputSecondColumn(double x, size_t max, double error)
{
  try
    {
      if (x < 0.0)
      {
        std::cout << " ";
      }
      else
      {
        std::cout << "  ";
      }
      std::cout << petrov::calculateByTaylor(x, max, error);
      std::cout << "    |";
    }
    catch (const std::logic_error & e)
    {
      if (x >= 0.0)
      {
        std::cout << "\b";
      }
      std::cout << "<MATH_ERROR> |";
    }
}

void petrov::outputThirdColumn(double x)
{
  if (x < 0.0)
  {
    std::cout << " ";
  }
  else
  {
    std::cout << "  ";
  }
  std::cout << petrov::calculateBySTD(x);
  std::cout << " |\n";
}
