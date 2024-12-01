#include <fstream>
#include <iostream>
#include "iomatrix.hpp"
#include "matrix_operations.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments" << "\n";
    return 1;
  }
  char * analysEnd = nullptr;
  size_t task = std::strtoll(argv[1], std::addressof(analysEnd), 10);

  if (*analysEnd != '\0')
  {
    std::cerr << "Invalid first argument" << "\n";
    return 1;
  }

  if (!((task == 2) || (task == 1)))
  {
    std::cerr << "Number of task is out of range" << "\n";
    return 2;
  }

  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Cannot read a number" << "\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Error: Output file is not open" << "\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows) || !(input >> cols))
  {
    std::cerr << "Can't read rows or columns" << "\n";
    return 2;
  }

  if ((rows == 0 && cols == 0))
  {
    std::cout << "Null matrix" << "\n";
    return 0;
  }

  size_t countOfElements = rows * cols;

  int tempMatrix[10000] = {};
  int *matrix = nullptr;

  if (task == 1)
  {
    matrix = tempMatrix;
  }
  else if (task == 2)
  {
    try
    {
      matrix = new int[countOfElements];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Error" << e.what() << "\n";
      delete[] matrix;
      return 2;
    }
  }
  try
  {
    shabalin::inputMatrix(input, matrix, countOfElements);
    shabalin::spiralDecrease(matrix, rows, cols);
    shabalin::outputMatrix(output, matrix, rows, cols);
    if (!output)
    {
      throw std::logic_error("Error of output");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    if (task == 2)
    {
      delete[] matrix;
    }
    return 2;
  }

  delete[] matrix;
  return 0;
}
