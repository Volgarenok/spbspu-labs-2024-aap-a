#include <iostream>
#include <fstream>
#include "matrixInputAndProcessing.hpp"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments!\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments!\n";
    return 1;
  }
  for (size_t i = 0; argv[1][i] != '\0'; i++)
  {
    if (!('0' <= argv[1][i] && argv[1][i] <= '9'))
    {
      std::cerr << "First parameter is not a number!\n";
      return 1;
    }
  }
  if (!(argv[1][0] == '2' || argv[1][0] == '1') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is out of range!\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;

  if (argv[1][0] == '1')
  {
    int matrix[10000] = {0};
    if (!krylov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Error: incorrect matrix!\n";
      return 2;
    }
    output << krylov::getColumnWithMaxEquals(matrix, rows, columns);
    output << '\n';
  }
  else if (argv[1][0] == '2')
  {
    int * matrix = new int[rows * columns];
    if (!krylov::inputMatrix(input, matrix, rows, columns))
    {
      std::cerr << "Error: incorrect matrix!\n";
      delete[] matrix;
      return 2;
    }

    output << krylov::getColumnWithMaxEquals(matrix, rows, columns);
    output << '\n';
    delete[] matrix;
  }
}
