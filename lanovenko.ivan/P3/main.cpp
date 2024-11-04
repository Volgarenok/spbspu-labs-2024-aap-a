#include <iostream>
#include "input_matrix.h"
#include "output_matrix.h"
#include <cstdlib>
#include <fstream>

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
    std::cerr << "Not a matrix";
    return 2;
  }
  std::ofstream output(argv[3]);
  if (num == 1)
  {
    int matrix[10000];
    if (!input_matrix(input, matrix, matrixsize))
    {
      std::cerr << "Fail input" << '\n';
      return 2;
    }
    output_matrix (output, matrix, rows, cols);
  }
  else
  {
    int *dmatrix = new int[matrixsize];
    if(!input_matrix(input, dmatrix, matrixsize))
    {
      delete[] dmatrix;
      std::cerr << "Fail input" << '\n';
      return 2;
    }
    output_matrix (output, dmatrix, rows, cols);
    delete[] dmatrix;
  }
}
