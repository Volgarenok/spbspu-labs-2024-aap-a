#include <iostream>
#include "input_matrix.h"
#include "output_matrix.h"
#include <cstdlib>
#include <fstream>
#include <cstring>
int main(int argc, char ** argv)
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
  int num = atoi(argv[1]);
  if (num == 0)
  {
    std::cerr << "Fist name is not a number" << '\n';
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
  if (num == 1)
  {
    int matrix[10000];
    if (!lanovenko::input_matrix(input, matrix, matrixsize))
    {
      std::cerr << "Fail input" << '\n';
      return 2;
    }
    lanovenko::output_matrix(output, matrix, rows, cols);
  }
  else
  {
    int *dmatrix = new int[matrixsize];
    if(!lanovenko::input_matrix(input, dmatrix, matrixsize))
    {
      delete[] dmatrix;
      std::cerr << "Fail input" << '\n';
      return 2;
    }
    lanovenko::output_matrix(output, dmatrix, rows, cols);
    delete[] dmatrix;
  }
  return 0;
}
