#include <iostream>
#include <fstream>
#include "matrix.h"
#include "periphery.h"

int main(int argc, char** argv)
{
  if (argc > 4)
  {
    std::cerr << "ERROR: Too many arguments!\n";
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "ERROR: Not enough arguments!\n";
    return 1;
  }
  else
  {
    if (!std::atoi(argv[1]))
    {
      std::cerr << "ERROR: First parameter is not an integer number!\n";
      return 1;
    }
    else if (std::atoi(argv[1]) != 1 && std::atoi(argv[1]) != 2)
    {
      std::cerr << "ERROR: First parameter is out of range!\n";
      return 1;
    }
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  int m = 0, n = 0;
  input >> m >> n;

  if (std::atoi(argv[1]) == 1)
  {
    constexpr int arraySize = 10000;
    int array[arraySize] = {};
    if (!aleksandrov::inputMatrix(input, array, m, n))
    {
      std::cerr << "ERROR: Input was incorrect!\n";
      return 2;
    }
    aleksandrov::periphery(array, m, n);
    aleksandrov::outputMatrix(output, array, m, n);
  }
  else if (std::atoi(argv[1]) == 2)
  {
    int* array = nullptr;
    try
    {
      array = new int[m * n];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "ERROR: Out of memory!\n";
      return 1;
    }
    if (!aleksandrov::inputMatrix(input, array, m, n))
    {
      std::cerr << "ERROR: Input was incorrect!\n";
      delete[] array;
      return 2;
    }
    aleksandrov::periphery(array, m, n);
    aleksandrov::outputMatrix(output, array, m, n);
    delete[] array;
  }
}

