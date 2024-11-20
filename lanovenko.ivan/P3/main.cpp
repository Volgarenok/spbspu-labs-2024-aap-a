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
  int num = argv[1][0];
  if ((argv[1][0] != '2' && argv[1][0] != '1') || argv[1][1] != '\0')
  {
    std::cerr << "First parametr is not a number" << '\n';
    return 1;
  }
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
      delete[] pointertodelete;
      std::cerr << "Out of memory" << '\n';
      return 2;
    }
  }

  if(!lanovenko::input_matrix(input, matrix, matrixsize))
  {
    std::cerr << "Input fail" << '\n';
    return 2;
  }
  lanovenko::changeto_LFT_TOP_CLK(matrix, rows, cols);
  for (size_t r = 0; r < rows; ++r)
  {
    for (size_t c = 0; c < cols; ++c)
    {
      output << matrix[r * cols + c] << " ";
    }
    output << '\n';
  }
  delete[] pointertodelete;
  return 0;
}
