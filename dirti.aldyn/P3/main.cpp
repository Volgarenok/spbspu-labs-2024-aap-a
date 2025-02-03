#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "matrix_functions.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Arguments number is not 4" << "\n";
    return 1;
  }
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not suitable" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "Input is incorrect" << "\n";
    return 2;
  }
  if (m == 0 && n == 0)
  {
    std::cout << "0 0\n";
    return 0;
  }
  int fix_matrix[10000] = {};
  int * matrix = nullptr;
  int * dyn_matrix = nullptr;
  if (argv[1][0] == '1')
  {
    matrix = fix_matrix;
  }
  else
  {
    try
    {
      dyn_matrix = new int[m * n];
      matrix = dyn_matrix;
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory" << "\n";
      return 2;
    }
  }
  size_t read = 0;
  dirti::input_matrix(input, matrix, m, n, read);
  if (read != (m * n))
  {
    std::cerr << "Incorrect values of matrix" << "\n";
    delete[] dyn_matrix;
    return 2;
  }
  if (!(dirti::matrix_checking(matrix, m, n)))
  {
    std::cout << "Matrix does not suit condition" << "\n";
    delete[] dyn_matrix;
    return 0;
  }
  std::ofstream output(argv[3]);
  output << dirti::local_min(matrix, m, n) << "\n";
  delete[] dyn_matrix;
  return 0;
}
