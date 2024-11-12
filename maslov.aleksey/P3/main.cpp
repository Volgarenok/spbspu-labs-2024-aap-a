#include <iostream>
#include <fstream>
#include <cstdlib>
#include "arrays.hpp"

int main(int argc, char **argv)
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
  char *endptr = nullptr;
  const long taskNumber = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (!(taskNumber == 1 || taskNumber == 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Rows or columns are not a number\n";
    return 2;
  }
  if (rows <= 0 || columns <= 0)
  {
    output << rows << " " << columns << "\n";
    return 0;
  }
  constexpr size_t maxSize = 10000;
  int fixedLengthArray[maxSize] = {};
  int *array = fixedLengthArray;
  if (taskNumber == 2)
  {
    const size_t arraySize = rows * columns;
    try
    {
      array = new int[arraySize];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
  }
  size_t read = 0;
  if (!maslov::inputMatrix(input, array, rows, columns, read))
  {
    std::cerr << "Elements are not a number or not enough\n";
    if (taskNumber == 2)
    {
      delete[] array;
    }
    return 2;
  }
  output << maslov::findLocalMaximum(array, rows, columns);
  output << "\n";
  if (taskNumber == 2)
  {
    delete[] array;
  }
}
