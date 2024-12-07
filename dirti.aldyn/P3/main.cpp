#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "input_matrix.hpp"
#include "matrix_checking.hpp"
#include "local_min.hpp"
int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not suitable" << "\n";
    return 1;
  }
  const int num = std::atoi(argv[1]);
  size_t m = 0, n = 0;
  size_t read = 0;
  std::ifstream input(argv[2]);
  input >> m >> n;
  if (m == 0 && n == 0)
  {
    std::cout << 0 << " " << 0 << "\n";
    return 0;
  }
  if (!input)
  {
    std::cerr << "Input is incorrect" << "\n";
    return 2;
  }
  int * dyn_matrix = nullptr;
  if (num == 1)
  {
    int matrix[10000] = {};
  }
  else
  {
    int * matrix = nullptr;
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
  dirti::input_matrix(input, matrix, m, n, read);
  if (read != (m * n))
  {
    std::cerr << "Incorrect values of matrix" << "\n";
    delete[] dyn_matrix;
    return 2;
  }
  if (!(dirti::matrix_checking(matrix, m, n)))
  {
    std::cerr << "Matrix does not suit condition" << "n";
    delete[] dyn_matrix;
    return 2;
  }
  std::ofstream output(argv[3]);
  output << dirti::local_min(matrix, m, n) << "\n";
  delete[] dyn_matrix;
  return 0;
}
