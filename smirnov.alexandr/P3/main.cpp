#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if ((num != 1 && num != 2) || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t rows = 0;
  size_t columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 2;
  }
  std::ofstream output(argv[3]);
  size_t sizeMatrix = rows * columns;
  constexpr size_t size = 10000;
  int fixedMatrix[size] = {0};
  int * dynamicMatrix = nullptr;
  int * matrix = nullptr;
  if (num == 1)
  {
    if (sizeMatrix > 10000)
    {
      std::cerr << "Too many matrix elements\n";
      return 1;
    }
    matrix = fixedMatrix;
  }
  else
  {
    try
    {
      dynamicMatrix = new int[sizeMatrix];
      matrix = dynamicMatrix;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] dynamicMatrix;
      std::cerr << "Out of memory\n";
      return 2;
    }
  }
  if (!smirnov::inputMatrix(input, matrix, sizeMatrix))
  {
    delete[] dynamicMatrix;
    std::cerr << "Input error\n";
    return 1;
  }
  smirnov::outputResult(output, matrix, rows, columns);
  delete[] dynamicMatrix;
}
