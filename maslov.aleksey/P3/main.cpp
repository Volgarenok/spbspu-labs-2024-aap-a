#include <iostream>
#include <fstream>
#include <cstdlib>
#include "arrays.hpp"

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
  char* endptr = nullptr;
  long taskNumber = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if(!(taskNumber == 1 || taskNumber == 2))
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
    std::cerr << "Rows or columns not a number\n";
    return 2;
  }
  if (rows <= 0 || columns <= 0)
  {
    std::cerr << "Matrix cannot be created\n";
    return 2;
  }

  size_t read = 0;
  int ** matrix = nullptr;
  try
  {
    matrix = maslov::createMatrix(rows,columns);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  maslov::inputMatrix(input, matrix, rows, columns, read);

  if (taskNumber == 1)
  {
    constexpr size_t max_size = 10000;
    int array[max_size] = {};
    int * staticArray = maslov::convert(matrix, rows,
        columns, array);
    maslov::destroyMatrix(matrix,rows);
  }
  else
  {
    const size_t arraySize = rows * columns;
    int * array = new int[arraySize];
    int * dynamicArray = maslov::convert(matrix,
        rows, columns, array);
  }
  // maslov::outputMatrix(output);
}
