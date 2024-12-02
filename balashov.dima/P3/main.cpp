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
  char* pEnd = nullptr;
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
  std::ifstream input(argv[2]);
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
  std::ofstream output(argv[3]);
  if (rows == 0 || columns == 0)
  {
    output << "0\n";
    return 0;
  }
  size_t read = 0;
  int matrixFixed[1000] = {};
  int* matrix = matrixFixed;
  int* pointerToDelete = nullptr;
  if (arrayType == 2)
  {
    try
    {
      matrix = new int[columns * rows];
      pointerToDelete = matrix;
    }
    catch (const std::bad_alloc& e)
    {
      delete[] pointerToDelete;
      std::cerr << "Out of memory\n";
      return 2;
    }
  }
  if (!(balashov::inputMatrix(input, matrix, columns, rows, read)))
  {
    std::cerr << "Invalid input\n";
    delete[] pointerToDelete;
    return 2;
  }
  output << balashov::calculateMinSumSideDiagonal(matrix, columns, rows) << "\n";
  delete[] pointerToDelete;
}
