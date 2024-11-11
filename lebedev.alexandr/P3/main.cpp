#include <iostream>
#include <cstdlib>
#include <fstream>
#include "table.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments!\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments!\n";
    return 1;
  }
  
  for (size_t i = 0; argv[1][i] != '\0'; ++i)
  {
    if (argv[1][i] < '0' || argv[1][i] > '9')
    {
      std::cerr << "First parametr is not a number!\n";
      return 1;
    }
  }

  int num = std::atoi(argv[1]);
  if (num < 1 || num > 2)
  {
    std::cerr << "First parameter is out of range!\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  size_t m = 0, n = 0;
  inputFile >> m >> n;
  if (!inputFile || n != m)
  {
    std::cerr << "Incorrect dimensions of the matrix!\n";
    return 2;
  }

  std::ofstream outputFile(argv[3]);
  constexpr size_t staticSize = 10000;
  int staticArr[staticSize];
  int* arr = staticArr;

  if (num == 2)
  {
    try
    {
      arr = new int[m * n];
    }
    catch(std::bad_alloc& e)
    {
      std::cerr << "Memory allocation error!\n";
      return 2;
    }
  }

  if (!lebedev::input(inputFile, arr, m))
  {
    std::cerr << "Incorrect data in the file\n";
    if (num == 2)
    {
      delete[] arr;
    }
    return 2;
  }
  
  lebedev::output(outputFile, arr, m);
  if (num == 2)
  {
    delete[] arr;
  }
  return 0;
}
