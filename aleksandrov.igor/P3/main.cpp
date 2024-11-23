#include <iostream>
#include <fstream>
#include "matrix.h"
#include "periphery.h"

int main(int argc, char** argv)
{
  size_t arg1 = 0;
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
    if (!std::isdigit(argv[1][0]) || argv[1][1] != '\0')
    {
      std::cerr << "ERROR: First parameter is incorrect!\n";
      return 1;
    }
    arg1 = std::atoi(argv[1]);
    if (arg1 != 1 && arg1 != 2)
    {
      std::cerr << "ERROR: First parameter is out of range!\n";
      return 1;
    }
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0;
  input >> m >> n;

  constexpr size_t arraySize = 10000;
  int arrayFixed[arraySize] = {};
  int* arrayDynamic = nullptr;
  int* array = nullptr;
  if (arg1 == 1)
  {
    array = arrayFixed;
  }
  else if (arg1 == 2)
  {
    try
    {
      arrayDynamic = new int[m * n];
      array = arrayDynamic;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "ERROR: Out of memory!\n";
      delete[] arrayDynamic;
      return 1;
    }
  }
  if (!aleksandrov::inputMatrix(input, array, m, n))
  {
    std::cerr << "ERROR: Input was incorrect!\n";
    delete[] arrayDynamic;
    return 2;
  }
  aleksandrov::periphery(array, m, n);
  aleksandrov::outputMatrix(output, array, m, n);
  delete[] arrayDynamic;
}

