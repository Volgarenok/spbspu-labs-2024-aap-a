#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "input_matrix.h"
#include "modification_matrix.h"
int main(int argc, char** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << '\n';
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "Not enough arguments" << '\n';
    return 1;
  }

  if ((argv[1][0] != '2' && argv[1][0] != '1') || argv[1][1] != '\0')
  {
    std::cerr << "First parametr is not a number" << '\n';
    return 1;
  }
  const char* str = argv[1];
  char* endptr = nullptr;
  long int num = 0;
  num = std::strtol(str, std::addressof(endptr), 10);
  size_t rows = 0;
  size_t cols = 0;
  size_t matrixsize = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Not a matrix" << '\n';
    return 2;
  }
  matrixsize = rows * cols;
  std::ofstream output(argv[3]);
  int fixedmatrix[10000]{};
  int* matrix = fixedmatrix;
  int* pointertodelete = nullptr;
  if (num == 2)
  {
    try
    {
      matrix = new int[matrixsize];
      pointertodelete = matrix;
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory" << '\n';
      return 2;
    }
  }

  if(!lanovenko::input_matrix(input, matrix, matrixsize))
  {
    std::cerr << "Input fail" << '\n';
    return 2;
  }
  lanovenko::editMatrix(matrix, rows, cols);
  for (size_t r = 0; r < rows; ++r)
  {
    for (size_t c = 0; c < cols; ++c)
    {
      if (c < cols - 1)
      {
        output << matrix[r * cols + c] << ' ';
      }
      else
      {
        output << matrix[r * cols + c];
      }
    }
    output << '\n';
  }
  delete[] pointertodelete;
  return 0;
}
