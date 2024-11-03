#include "input_matrix.h"
#include "output_matrix.h"
#include <iostream>
#include <fstream>

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
  long int num = 0;
  const char* str = argv[1];
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parametr is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t line = 0;
  size_t column = 0;
  size_t matrix_size = 0;
  input >> line >> column;
  if (!input)
  {
    std::cerr << "Not a matrix\n";
    return 2;
  }
  matrix_size = line * column;
  if (num == 1)
  {
    int matrix[10000];
    if (!timofeev::input_matrix(input, matrix, matrix_size))
    {
      std::cerr << "Fail input\n";
      return 2;
    }
    timofeev::output_matrix(output, matrix, line, column);
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
    timofeev::output_matrix(output, dmatrix, line, column);
    delete[] dmatrix;
  }
  return 0;
}
