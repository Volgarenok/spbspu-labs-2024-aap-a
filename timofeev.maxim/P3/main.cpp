#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "input_matrix.h"
#include "output_matrix.h"
#include "cut_to_square.h"

int main(int argc, char** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  else if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t line = 0;
  size_t column = 0;
  size_t matrix_size = 0;
  input >> line >> column;
  size_t size = (column <= line) ? column : line;
  if (!input)
  {
    std::cerr << "Not a matrix\n";
    return 2;
  }
  matrix_size = line * column;
  if (matrix_size == 0)
  {
    output << line << column;
    return 0;
  }
  if (num == 1)
  {
    int matrix[10000];
    if (!timofeev::input_matrix(input, matrix, matrix_size))
    {
      std::cerr << "Fail input\n";
      return 2;
    }
    timofeev::cut_to_square(matrix, line, column);
    if (timofeev::check_diag(matrix, size))
    {
      output << "The matrix contains diagonals with equal values";
    }
    else
    {
      output << "The matrix doesn't contain diagonals with equal values";
    }
  }
  else if (num == 2)
  {
    int* dmatrix = nullptr;
    try
    {
      dmatrix = new int[matrix_size];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (!timofeev::input_matrix(input, dmatrix, matrix_size))
    {
      delete[] dmatrix;
      std::cerr << "Fail input\n";
      return 2;
    }
    timofeev::cut_to_square(dmatrix, line, column);
    if (timofeev::check_diag(dmatrix, size))
    {
      output << "The matrix contains diagonals with equal values";
    }
    else
    {
      output << "The matrix doesn't contain diagonals with equal values";
    }
    delete[] dmatrix;
  }
  return 0;
}
