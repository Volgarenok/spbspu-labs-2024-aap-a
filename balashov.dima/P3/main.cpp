#include <iostream>
#include <cstdlib>
#include "stream.hpp"
#include "matrixProcessing.hpp"

int main(int argc, char** argv)
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
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  char * pEnd = nullptr;
  const long arrayType = std::strtol(argv[1], &pEnd, 10);

  if (*pEnd != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if ((arrayType == 1 || arrayType == 2) == false)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  int columns = 0, rows = 0;
  input >> columns >> rows;
  if (!input)
  {
    std::cerr << "Rows or columns are not a number\n";
    return 2;
  }
  if (columns < 0 || rows < 0)
  {
    std::cerr << "Rows and columns must be greater than 0\n";
    return 2;
  }
  if (rows == 0 || columns == 0)
  {
    output << "0\n";
    return 0;
  }
  size_t read = 0;
  if (arrayType == 1)
  {
    int matrix[1000] = {};
    if (!(balashov::inputMatrix(input, matrix, columns, rows, read)))
    {
      std::cerr << "ERROR: Invalid input\n";
      return 2;
    }
    output << balashov::minSumSideDiagonal(matrix, columns, rows) << "\n";
  }
  else if (arrayType == 2)
  {
    int * matrix = nullptr;
    try
    {
      matrix = new int[columns * rows];
    }
    catch (const std::bad_alloc & e)
    {
      delete[] matrix;
      std::cerr << "Out of memory\n";
      return 2;
    }

    if (!(balashov::inputMatrix(input, matrix, columns, rows, read)))
    {
      delete[] matrix;
      std::cerr << "ERROR: Invalid input\n";
      return 2;
    }
    output << balashov::minSumSideDiagonal(matrix, columns, rows) << "\n";
    delete[] matrix;
  }
return 0;
}
