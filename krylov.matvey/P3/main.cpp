#include <iostream>
#include <fstream>
#include "matrixProcessing.hpp"

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
  if (!(argv[1][0] == '2' || argv[1][0] == '1') || argv[1][1] != '\0')
  {
    std::cerr << "Incorrect first parameter!\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  int *matrix = nullptr;
  int staticArray[10000] = {0};
  if (argv[1][0] == '1')
  {
    matrix = staticArray;
  }
  else if (argv[1][0] == '2')
  {
    matrix = new int[rows * columns];
  }
  if (!krylov::inputMatrix(input, matrix, rows, columns))
  {
    std::cerr << "Error: incorrect matrix!\n";
    if (argv[1][0] == '2')
    {
      delete[] matrix;
    }
    return 2;
  }
  output << krylov::getColumnWithMaxEquals(matrix, rows, columns);
  output << '\n';
  if (argv[1][0] == '2')
  {
    delete[] matrix;
  }
}
